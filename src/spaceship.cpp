#include "spaceship.hpp"
#include <raylib.h>

Spaceship::Spaceship() {
    jump = 7;
    image = LoadTexture("graphics/spaceship.png");
    position.y = (GetScreenHeight() - image.height);
    position.x = (GetScreenWidth() - image.width) / 2.0;
    this->lastFireTime = 0.0;
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    ;
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
    ;
}

void Spaceship::MoveLeft() {
    position.x -= jump;
    if (position.x < 0) { // INFO: if gets to the border, go to the other side
        position.x = GetScreenWidth();
    }
}
void Spaceship::MoveRight() {
    position.x += jump;
    if (position.x >
        GetScreenWidth()) { // INFO: if gets to the border, go to the other side
        position.x = 0;
    };
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) {
        Laser laser = Laser({position.x + image.width / 2 - 2, position.y}, -7);
        lasers.emplace_back(laser);
        lastFireTime = GetTime();
    }
}

Rectangle Spaceship::getRect() {
    return {position.x, position.y, float(image.width), float(image.height)};
}

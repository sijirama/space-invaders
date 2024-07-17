#include "mysteryship.hpp"
#include <raylib.h>

MysteryShip::MysteryShip() {
    image = LoadTexture("graphics/mystery.png");
    alive = false;
}

MysteryShip::~MysteryShip() {
    UnloadTexture(image);
    ;
}

void MysteryShip::Spawn() {
    position.y = 90;
    int side = GetRandomValue(0, 1);

    if (side == 0) {
        position.x = 0;
        speed = 4;
    } else {
        position.x = GetScreenWidth() - image.width;
        speed = -3;
    }
    alive = true;
}

void MysteryShip::Update() {
    if (alive) {
        position.x += speed;
        if (position.x > GetScreenWidth() - image.width || position.x < 0) {
            alive = false;
        }
    }
}

void MysteryShip::Draw() {
    if (alive) {
        DrawTextureV(image, position, WHITE);
    }
}

Rectangle MysteryShip::getRect() {
    if (alive) {
        return {position.x, position.y, float(image.width),
                float(image.height)};
    } else {
        return {position.x, position.y, 0, 0};
    }
};

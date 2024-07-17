#include "laser.hpp"
#include <raylib.h>
// #include <iostream>

Laser::Laser(Vector2 positionArg, int speed) {
    this->postion = positionArg;
    this->speed = speed;
    this->active = true;
}

void Laser::Draw() {
    if (active)
        DrawRectangle(this->postion.x, this->postion.y, 4, 15,
                      {243, 216, 63, 255});
}

void Laser::Update() {
    postion.y += speed;
    if (active) {
        if (postion.y > GetScreenHeight() || postion.y < 0) {
            this->active = false;
            // std::cout << "Laser Inactive" << std::endl;
        }
    };
}

Rectangle Laser::getRect() {
    return {postion.x, postion.y, 4, 15};
    //     if (active) {
    // } else {
    //     return {postion.x, postion.y, 0, 0};
    // }
}

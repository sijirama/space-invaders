#pragma once

#include <raylib.h>
#include <vector>
#include "laser.hpp"

class Spaceship {
  public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();

    std::vector<Laser> lasers;
    Rectangle getRect();

  private:
    Texture2D image;
    Vector2 position;
    double lastFireTime;
    int jump;
};

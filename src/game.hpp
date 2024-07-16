#pragma once
#include <vector>
#include "obstacle.hpp"
#include "spaceship.hpp"

class Game {
  public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();

  private:
    void DeleteInactiveLasers();
    Spaceship spaceship;
    std::vector<Obstacle> CreateObstacles();
    std::vector<Obstacle> obstacles;
};

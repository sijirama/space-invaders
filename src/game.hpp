#pragma once
#include <vector>
#include "alien.hpp"
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
    std::vector<Alien> CreateAliens();
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;

    void MoveAliens();
    void MoveDownAliens(int distance);
    int AlienDirection;
};

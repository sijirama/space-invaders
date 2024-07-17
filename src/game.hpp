#pragma once
#include <vector>
#include "alien.hpp"
#include "laser.hpp"
#include "mysteryship.hpp"
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
    std::vector<Laser> AlienLasers;
    void AlienShootLasers();
    constexpr static float alienShootLaserInterval = 0.35;
    float timeLastAlienFired;
    MysteryShip mysteryship;
    float mysteryShipSpawnInterval;
    float timeLastSpawn;
};

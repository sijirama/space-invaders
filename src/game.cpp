#include "game.hpp"
#include <raylib.h>
#include "alien.hpp"
#include "spaceship.hpp"

Game::Game() {
    obstacles = CreateObstacles();
    aliens = CreateAliens();
    AlienDirection = 1;
    timeLastAlienFired = 0.0;
}

Game::~Game() { Alien::UnloadImages(); }

void Game::Update() {

    for (auto& laser : spaceship.lasers) {
        laser.Update();
    }

    MoveAliens();
    AlienShootLasers();
    for (auto& lasers : AlienLasers) {
        lasers.Update();
    }
    DeleteInactiveLasers();
}

void Game::Draw() {
    spaceship.Draw();

    for (auto& laser : spaceship.lasers) {
        laser.Draw();
    }

    for (auto& obstacle : obstacles) {
        obstacle.Draw();
    }

    for (auto& alien : aliens) {
        alien.Draw();
    }

    for (auto& lasers : AlienLasers) {
        lasers.Draw();
    }
}

void Game::HandleInput() {
    if (IsKeyDown(KEY_LEFT)) {
        spaceship.MoveLeft();
    } else if (IsKeyDown(KEY_RIGHT)) {
        spaceship.MoveRight();
    } else if (IsKeyDown(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}
void Game::DeleteInactiveLasers() {
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (!it->active) {
            it = spaceship.lasers.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles() {
    auto obstacleWidth = Obstacle::grid[0].size();
    float gap = (GetScreenWidth() - (obstacleWidth * 4)) / 5.0;
    for (int i = 0; i < 4; ++i) {
        float offsetX = (i + 1) * gap + 1 * obstacleWidth;
        obstacles.push_back(
            Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAliens() {
    std::vector<Alien> aliens;

    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 11; ++column) {

            int alientype;

            if (row == 0) {
                alientype = 3;
            } else if (row <= 2) {
                alientype = 2;
            } else {
                alientype = 1;
            }

            float x = 75 + column * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(alientype, {x, y}));
        }
    }

    return aliens;
}

void Game::MoveAliens() {
    for (auto& alien : aliens) {
        if (alien.position.x + alien.alienImages[alien.type - 1].width >
            GetScreenWidth()) {
            AlienDirection = -1;
            MoveDownAliens(3);
        }

        if (alien.position.x < 0) {
            AlienDirection = 1;
            MoveDownAliens(3);
        }
        alien.Update(AlienDirection);
    }
}

void Game::MoveDownAliens(int distance) {
    for (auto& alien : aliens) {
        alien.position.y += distance;
    }
}

void Game::AlienShootLasers() {
    double currentTime = GetTime();
    if (currentTime - timeLastAlienFired >= alienShootLaserInterval &&
        !aliens.empty()) {

        int randomIndex = GetRandomValue(0, aliens.size() - 1);
        Alien& alien = aliens[randomIndex];
        AlienLasers.push_back(Laser(
            {alien.position.x + alien.alienImages[alien.type - 1].width / 2,
             alien.position.y + alien.alienImages[alien.type].height},
            6));

        timeLastAlienFired = currentTime;
    }
}

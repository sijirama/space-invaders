#pragma once
#include <raylib.h>
#include <vector>
#include "block.hpp"

using namespace std; // for my sanity pls, i normally try not to use it

class Obstacle {
  public:
    Obstacle(Vector2 position);
    void Draw();
    std::vector<Block> blocks;
    Vector2 position;
    static vector<vector<int>> grid;

  private:
};

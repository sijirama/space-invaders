#pragma once

#include <raylib.h>

class Alien {
  public:
    Alien(int type, Vector2 position);

    // Texture2D image;
    static Texture2D alienImages[3];
    int type;
    Vector2 position;

    void Draw();
    void Update();
    int GetType();

  private:
};

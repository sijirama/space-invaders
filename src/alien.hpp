#pragma once

#include <raylib.h>

class Alien {
  public:
    Alien(int type, Vector2 position);
    static void UnloadImages();
    // Texture2D image;
    static Texture2D alienImages[3];
    int type;
    Vector2 position;

    void Draw();
    void Update(int direction);
    int GetType();

  private:
};

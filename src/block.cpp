#include "block.hpp"
#include <raylib.h>

Block::Block(Vector2 position) {
    this->position = position;
    ;
}

void Block::Draw() {
    DrawRectangle(this->position.x, this->position.y, 3, 3,
                  {243, 216, 63, 255});
}

Rectangle Block::getRect() {
    return {position.x, position.y, 3, 3};
    ;
}

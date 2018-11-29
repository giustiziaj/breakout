#include "Block.hpp"

using namespace std;
using namespace sf;

Block::Block(Vector2f _pos):
  BaseObject("block", _pos, "resources/block1.png") {
    sprite->setOrigin(30, 15);
}


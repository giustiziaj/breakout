#include <cmath>
#include "Paddle.hpp"
#include "Definitions.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

Paddle::Paddle(Vector2f _pos):
  BaseObject("paddle", _pos, "resources/paddle.png") {
  sprite->setOrigin(30, 0);
}

void Paddle::step() {
  if(Keyboard::isKeyPressed(Keyboard::Left)) {
    sprite->move(-P_SPEED, 0);
  }
  else if (Keyboard::isKeyPressed(Keyboard::Right)) {
    sprite->move(P_SPEED, 0);
  }
  if (sprite->getPosition().x > W_WIDTH) {
    sprite->setPosition(0, sprite->getPosition().y);
  }
  if (sprite->getPosition().x < 0) {
    sprite->setPosition(W_WIDTH, sprite->getPosition().y);
  }
}
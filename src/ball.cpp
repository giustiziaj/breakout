#include <random>
#include <cmath>

#include "Ball.hpp"
#include "Definitions.hpp"

using namespace std;
using namespace sf;

void normalize(Vector2f& v) {
  float mag = sqrt(v.x*v.x + v.y*v.y);
  v /= mag;
}

Vector2f initialDirection() {
  Vector2f v = Vector2f(rand(), rand());
  normalize(v);
  return v;
}

Ball::Ball(Vector2f _pos):
  velocity(B_SPEED),
  direction(initialDirection()),
  BaseObject("ball", _pos, "resources/ball.png") {
    sprite->setOrigin(15, 15);
}

void Ball::step() {
  sprite->move(direction * velocity);
  for (BaseObject* other: game->getCollisions(this)) {
    if (other->getName() == "paddle") {
      direction.y *= -1;
    }
    if (other->getName() == "block") {

    }
  }
  if (sprite->getGlobalBounds().left < 0
    || sprite->getGlobalBounds().left + 30 > W_WIDTH) {
      direction.x *= -1;
  }
  if (sprite->getGlobalBounds().top < 0
    || sprite->getGlobalBounds().top + 30 > W_HEIGHT) {
      direction.y *= -1;
  }


}
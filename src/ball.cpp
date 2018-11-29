#include <random>
#include <cmath>
#include <iostream>

#include "Ball.hpp"
#include "Definitions.hpp"

using namespace std;
using namespace sf;

/**
 * @brief normalize vector to unit distance
 *
 * @param v the Vector
 */
void normalize(Vector2f& v) {
  float mag = sqrt(v.x*v.x + v.y*v.y);
  v /= mag;
}

Vector2f initialDirection() {
  Vector2f v = Vector2f(rand(), rand());
  normalize(v);
  if (v.y < .2 || v.y > .8) v = initialDirection();
  return v;
}

Ball::Ball(Vector2f _pos):
  velocity(B_MINSPEED),
  direction(initialDirection()),
  BaseObject("ball", _pos, "resources/ball.png") {
    sprite->setOrigin(15, 15);
}

void Ball::bounceOff(BaseObject* other) {
  FloatRect block = other->getSprite()->getGlobalBounds();
  FloatRect ball = sprite->getGlobalBounds();
  int xd = ((block.left + block.width / 2) - (ball.left + ball.width / 2));
  int yd = ((block.top + block.height / 2) - (ball.top + ball.height / 2));
  if (xd < 0) {
    direction.x *= -1;
  }
  if (yd < 0) {
    direction.y *= -1;
  }
  if (xd > yd) {
    direction.x *= -1;
  }
  else {
    direction.y *= -1;
  }
  int d20 = rand() % 20;
  if (d20 == 1) {
    direction.y *= 1.1;
  } else if (d20 == 2) {
    direction.y *= .9;
  } else if (d20 == 3 && velocity < B_TOPSPEED) {
    velocity += .5;
  } else if (d20 == 4 && velocity > B_MINSPEED) {
    velocity -= .5;
  }
}

void Ball::step() {
  normalize(direction);
  sprite->move(direction * velocity);
  for (BaseObject* other: game->getCollisions(this)) {
    if (other->getName() == "paddle") {
      bounceOff(other);
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
        direction.x -= 1;
      } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        direction.x += 1;
      }
    }
    if (other->getName() == "block") {
      bounceOff(other);
      game->removeObject(other);
      game->setScore(game->getScore() + 1);
    }
  }
  if (sprite->getGlobalBounds().left < 0 ||
      sprite->getGlobalBounds().left + 30 >= W_WIDTH) {
    direction.x *= -1;
    if (sprite->getGlobalBounds().left < 0)
      sprite->move(.1, 0);
    else
      sprite->move(-.1, 0);
  }
  if (sprite->getGlobalBounds().top < 0) {
    direction.y *= -1;
    if (sprite->getGlobalBounds().top < 0)
      sprite->move(0, .1);
    else
      sprite->move(0, -.1);
  }
  if (sprite->getGlobalBounds().top + 30 >= W_HEIGHT) {
    game->gameOver(false);
  }
}
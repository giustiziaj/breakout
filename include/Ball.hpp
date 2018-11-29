#pragma once
#include "BaseObject.hpp"
#include "Game.hpp"

class Ball: public BaseObject {
public:
  Ball(sf::Vector2f);
  virtual void step();
private:
  sf::Vector2f direction;
  float velocity;
};
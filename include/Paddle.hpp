#pragma once
#include "BaseObject.hpp"

class Paddle: public BaseObject {
public:
  Paddle(sf::Vector2f);
  virtual void step();
};
#pragma once
#include "BaseObject.hpp"
#include "Game.hpp"

class Ball: public BaseObject {
public:
  /**
   * @brief Construct a new Ball object
   *
   */
  Ball(sf::Vector2f);

  /**
   * @brief called every frame, moves ball and detects bounces
   *
   */
  virtual void step();
private:
  /**
   * @brief bounce off another object
   *
   */
  void bounceOff(BaseObject*);

  sf::Vector2f direction;
  float velocity;
};
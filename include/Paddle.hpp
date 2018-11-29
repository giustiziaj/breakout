#pragma once
#include "BaseObject.hpp"

class Paddle: public BaseObject {
public:
  /**
   * @brief Construct a new Paddle object
   *
   */
  Paddle(sf::Vector2f);

  /**
   * @brief called every frame
   *
   */
  virtual void step();
};
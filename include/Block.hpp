#pragma once
#include "BaseObject.hpp"

class Block: public BaseObject {
public:
  /**
   * @brief Construct a new Block object at given position
   *
   */
  Block(sf::Vector2f);
};
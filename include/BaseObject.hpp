#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Game.hpp"
class Game; // Forward declaration for cyclic class

/**
 * @brief Parent class for all game objects
 *
 */
class BaseObject {
public:
  /**
   * @brief method called on every game object, every frame
   *
   */
  virtual void step() {};
  /**
   * @brief Get the Sprite object
   *
   * @return sf::Sprite*
   */
  sf::Sprite* getSprite();
  /**
   * @brief check for collision between objects
   *
   * @return true if there is a collision
   * @return false otherwise
   */
  bool collides(BaseObject*);
  /**
   * @brief Get the Name object
   *
   * @return std::string
   */
  std::string getName() const;

protected:
  /**
   * @brief Construct a new Base Object object
   *
   * @param object name
   * @param starting position
   * @param texture path
   */
  BaseObject(std::string, sf::Vector2f, std::string);
  sf::Sprite* sprite;
  std::string name;
  const Game* game;
};
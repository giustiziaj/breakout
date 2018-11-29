#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Game.hpp"
class Game;

class BaseObject {
public:
  virtual void step() {};
  sf::Sprite* getSprite();
  bool collides(BaseObject*);
  std::string getName() const;

protected:
  BaseObject(std::string, sf::Vector2f, std::string);
  sf::Sprite* sprite;
  std::string name;
  const Game* game;
};
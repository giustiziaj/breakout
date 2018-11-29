#pragma once
#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "BaseObject.hpp"
class BaseObject;

class Game {
public:
  static const Game* getGame();
  int run();
  void addObject(BaseObject*);
  std::vector<BaseObject*>& getCollisions(BaseObject*) const;
  sf::Texture* getTexture(std::string) const;
  ~Game();

protected:
  Game();

private:
  sf::RenderWindow* window;
  sf::Clock* gameClock;
  std::vector<BaseObject*>* objects;
  std::map<std::string, sf::Texture*>* textures;
  static const Game* instance;
};

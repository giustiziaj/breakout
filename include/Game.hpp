#pragma once
#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "BaseObject.hpp"
class BaseObject; // forward declaration

/**
 * @brief game singleton is the central controller for all game functionality
 *
 */
class Game {
public:
  /**
   * @brief Get the Game singleton object
   *
   * @return const Game*
   */
  static Game* getGame();
  /**
   * @brief run the game
   *
   * @return int exit status
   */
  int run();
  /**
   * @brief insert game object into game
   *
   */
  void addObject(BaseObject*);

  /**
   * @brief remove an object from the game
   *
   */
  void removeObject(BaseObject*);

  /**
   * @brief Get the Collisions for a given game object
   *
   * @return std::vector<BaseObject*>& list of colliding objects
   */
  std::vector<BaseObject*>& getCollisions(BaseObject*);
  /**
   * @brief Load texture if not yet loaded, otherwise fetch from texture map
   *
   * @return sf::Texture* the texture object
   */
  sf::Texture* getTexture(std::string);

  /**
   * @brief show the game over screen
   *
   */
  void gameOver(bool);

  /**
   * @brief Destroy the Game object
   *
   */
  ~Game();

  int getScore() const;
  void setScore(int);

protected:
  /**
   * @brief Protected constructor for singleton
   *
   */
  Game();

private:
  sf::RenderWindow* window;
  int score = 0;
  sf::Clock* gameClock;
  std::vector<BaseObject*>* objects;
  std::map<std::string, sf::Texture*>* textures;
  static Game* instance;
};

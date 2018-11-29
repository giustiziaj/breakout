#include <algorithm>
#include <random>
#include <iostream>

#include "Game.hpp"
#include "Definitions.hpp"

using namespace std;
using namespace sf;

Game* Game::instance = NULL;

Game::Game():
  objects(new vector<BaseObject*>()),
  textures(new map<string, Texture*>()),
  gameClock(new Clock()),
  window(new RenderWindow(
    VideoMode(W_WIDTH, W_HEIGHT),
    W_TITLE,
    Style::Close)) {
  srand(time(0));
  window->setVerticalSyncEnabled(true);
}

Texture* Game::getTexture(string tName) {
  if ((*textures)[tName]) {
    return (*textures)[tName];
  }
  Texture* tex = new Texture();
  tex->loadFromFile(tName);
  (*textures)[tName] = tex;
  return tex;
}

Game::~Game() {
  window->close();
}

Game* Game::getGame() {
  if (!instance) instance = new Game();
  return instance;
}

void Game::addObject(BaseObject* object) {
  objects->push_back(object);
}

void Game::removeObject(BaseObject* object) {
  objects->erase(
    remove(objects->begin(), objects->end(), object),
    objects->end());
}

vector<BaseObject*>& Game::getCollisions(BaseObject* object) {
  vector<BaseObject*>* collisions = new vector<BaseObject*>;
  for (BaseObject* other: *objects) {
    if (object->collides(other)) {
      collisions->push_back(other);
    }
  }
  return *collisions;
}

int Game::run() {
  while (window->isOpen()) {
    Event event;
    while (window->pollEvent(event)) {
      switch(event.type) {
        case Event::Closed:
          window->close();
          break;
        default:
          break;
      }
    }
    window->clear();
    for (BaseObject* object: *objects) {
      object->step();
      window->draw(*object->getSprite());
    }
    window->display();
  }
  return 0;
}
#include "BaseObject.hpp"

using namespace std;
using namespace sf;

BaseObject::BaseObject(string _name, Vector2f _pos, string _tex):
  name(_name),
  game(Game::getGame()) {
    sprite = new Sprite(*Game::getGame()->getTexture(_tex));
    sprite->setPosition(_pos);
}

string BaseObject::getName() const {
  return name;
}

Sprite* BaseObject::getSprite() {
  return sprite;
}

bool BaseObject::collides(BaseObject* other) {
  return sprite->getGlobalBounds().intersects(
         other->getSprite()->getGlobalBounds())
      && this != other;
}
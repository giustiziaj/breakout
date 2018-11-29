#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

using namespace std;
using namespace sf;

int main() {
  Game game = *Game::getGame();

  game.addObject(new Ball(Vector2f(300, 300)));
  game.addObject(new Paddle(Vector2f(300, 540)));

  return game.run();
}
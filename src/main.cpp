#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

using namespace std;
using namespace sf;

int main() {
  // initialize new game singleton
  Game game = *Game::getGame();

  // add the ball
  game.addObject(new Ball(Vector2f(300, 300)));

  // add the paddle
  game.addObject(new Paddle(Vector2f(300, 540)));

  // run the game
  return game.run();
}
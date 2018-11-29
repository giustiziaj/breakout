#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Block.hpp"

using namespace std;
using namespace sf;

int main() {
  // initialize new game singleton
  Game game = *Game::getGame();

  // add the ball
  game.addObject(new Ball(Vector2f(300, 300)));

  // add the paddle
  game.addObject(new Paddle(Vector2f(300, 540)));

  // add some blocks
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 6; j++)
      game.addObject(new Block(Vector2f(i * 60 + 30, j * 30 - 15)));

  // run the game
  return game.run();
}
#include "game.h"

Game::Game()
{
  in_play = false;
  game_over = false;
  bat_x = 0;
  ball_x = 0;
  bat_y = 228;
  ball_y = 228;
  ball_move_horiz = BALL_MOVE_RIGHT;
  ball_move_vert = BALL_MOVE_UP;
}

int Game::check_game_over()
{
  int diff = bat_x-ball_x;
  if((diff<-40) || (diff>10))
  {
    in_play = false;
    game_over = true;
    return 1;
  }
  return 0;
}

void Game::setBatX(int pos)
{
  bat_x = pos;
}

void Game::setBallX(int pos)
{
  ball_x = pos;
}

int Game::getBatX()
{
  return bat_x;
}

int Game::getBallX()
{
  return ball_x;
}

void Game::setBatY(int pos)
{
  bat_y = pos;
}

void Game::setBallY(int pos)
{
  ball_y = pos;
}

int Game::getBatY()
{
  return bat_y;
}

int Game::getBallY()
{
  return ball_y;
}

void Game::setGameOver(int val)
{
  game_over = val;
}

void Game::setInPlay(int val)
{
  in_play = val;
}

int Game::getGameOver()
{
  return game_over;
}

int Game::getInPlay()
{
  return in_play;
}

void Game::moveBatLeft(int amount)
{
  bat_x-=amount;
  if(bat_x < 0)
    bat_x=0;
}

void Game::moveBatRight(int amount)
{
  bat_x+=amount;
  if(bat_x > BAT_LIMIT)
    bat_x=BAT_LIMIT;
}

void Game::moveBallLeft(int amount)
{
  ball_x-=amount;
}

void Game::moveBallRight(int amount)
{
  ball_x+=amount;
}

void Game::moveBallDown(int amount)
{
  ball_y+=amount;
}

void Game::moveBallUp(int amount)
{
  ball_y-=amount;
}

int Game::hasBallHitWall()
{
  return (ball_x < 0) || (ball_x > BALL_X_LIMIT);
}

int Game::hasBallHitBottom()
{
  return ball_y > BALL_Y_BOTTOM_LIMIT-11;
}

int Game::hasBallHitTop()
{
  return ball_y < BALL_Y_TOP_LIMIT;
}

void Game::setBallVerticalMovement(int direction)
{
  ball_move_vert = direction;
}

void Game::setBallHorizontalMovement(int direction)
{
  ball_move_horiz = direction;
}

int Game::getBallVerticalMovement()
{
  return ball_move_vert;
}

int Game::getBallHorizontalMovement()
{
  return ball_move_horiz;
}
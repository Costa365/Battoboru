/*
  Bat and Ball game for Original RG350 Handheld console

  Based on RG350 Test by Rafa Vico
  https://github.com/RafaVico/rg350_test

*/

#include <SDL/SDL.h>
#include "rumble.h"
#include "joystick.h"
#include "highscore.h"
#include "graphics.h"
#include "game.h"
#include "audio.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

SDL_Surface* screen;

int done = 0;

int score = 0;
int high_score = 0;

SDL_Surface *surfaceBat;
SDL_Surface *surfaceBall;
SDL_Surface *surfaceTitle;

Rumble *rumble;
Joystick *joystick;
HighScore *highscore;
Graphics *graphics;
Game *game;
Audio *audio;

const char *highScoreFile = "/usr/local/home/battoburu.score";

void initGame();
void endGame();
void processJoystick();
void playHitTop();
void playHitBat();
void playHitSide();
void moveBall();
void drawGame();
void updateGame();

void initGame()
{
  srand(time(NULL));
 
  SDL_ShowCursor(0);

  graphics = new Graphics();
  graphics->loadImageAplha(screen, "media/bat.png", surfaceBat);
  graphics->loadImageAplha(screen, "media/ball.png", surfaceBall);
  graphics->loadImageAplha(screen, "media/title.png", surfaceTitle);

  audio = new Audio();
  audio->addSound("media/hit1.wav");
  audio->addSound("media/hit2.wav");
  audio->addSound("media/hit3.wav");

  rumble = new Rumble();
  joystick = new Joystick();
  highscore = new HighScore(highScoreFile);
  game = new Game();

  high_score = highscore->readHighScore();
}

void endGame()
{
  SDL_FillRect(screen, NULL, 0x000000);

  if(surfaceBat)
    SDL_FreeSurface(surfaceBat);

  if(surfaceBall)
    SDL_FreeSurface(surfaceBall);

  if(surfaceTitle)
    SDL_FreeSurface(surfaceTitle);

  delete rumble;
  delete joystick;
  delete highscore;
  delete graphics;
  delete game;
  delete audio;
}

void processJoystick()
{
  if(joystick->getButtonState(GCW_BUTTON_L1) && 
    joystick->getButtonState(GCW_BUTTON_START))
  {
    done=1;
    return;
  }  

  if(joystick->getButtonState(GCW_BUTTON_LEFT))
  {;
    game->moveBatLeft(3);
  }

  if(joystick->getButtonState(GCW_BUTTON_RIGHT))
  {
    game->moveBatRight(3);
  }

  if(joystick->getButtonState(GCW_BUTTON_START))
  {
    if(!game->getInPlay())
    {
      int x_pos = rand() % 280;
      game->setBatX(x_pos);
      game->setBatY(228);
      game->setBallX(x_pos);
      game->setBallY(228);
      game->setBallVerticalMovement(BALL_MOVE_UP);
      game->setBallHorizontalMovement(BALL_MOVE_RIGHT);
      game->setGameOver(false);
      game->setInPlay(true);
      score = 0;
    }
  }
}

void playHitTop()
{
  audio->playSound(2);
}

void playHitBat()
{
  audio->playSound(1);
}

void playHitSide()
{
  audio->playSound(0);
}

void moveBall()
{
  int ball_move_amount = 2 + (score/5);
  if(game->getBallHorizontalMovement()==BALL_MOVE_LEFT)
  {
    game->moveBallLeft(ball_move_amount);
    if(game->hasBallHitWall())
    {
      game->setBallHorizontalMovement(BALL_MOVE_RIGHT);
      playHitSide();
    }
  }
  else
  {
    game->moveBallRight(ball_move_amount);
    if(game->hasBallHitWall())
    {
      game->setBallHorizontalMovement(BALL_MOVE_LEFT);
      playHitSide();
    }
  }

  if(game->getBallVerticalMovement()==BALL_MOVE_DOWN)
  {
    game->moveBallDown(ball_move_amount);
    if(game->hasBallHitBottom())
    {
      game->setBallVerticalMovement(BALL_MOVE_UP);
      
      if(game->check_game_over()==1)
      {
        if(score > high_score)
        {
          high_score = score;
          highscore->writeHighScore(high_score);
        }
        rumble->playRumble();
      }
      else
      {
        playHitBat();
        score++;
      }
    }
  }
  else
  {
    game->moveBallUp(ball_move_amount);
    if(game->hasBallHitTop())
    {
      game->setBallVerticalMovement(BALL_MOVE_DOWN);
      playHitTop();
    }
  }
}


void drawGame()
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));
  SDL_Rect dest;
  char text_str[20];

  if(game->getInPlay())
  {
    graphics->drawLine(screen,0,BALL_Y_TOP_LIMIT-1,SCREEN_WIDTH,BALL_Y_TOP_LIMIT-1,
      SDL_MapRGB(screen->format,255,255,0));

    sprintf(text_str,"High Score: %d",high_score);
    graphics->drawText(screen,text_str,2,1,255,255,0);

    sprintf(text_str,"Score: %3d",score);
    graphics->drawText(screen,text_str,268,1,255,255,0);

    dest.x=game->getBatX();
    dest.y=game->getBatY();

    if(surfaceBat)
      SDL_BlitSurface(surfaceBat,NULL,screen,&dest);

    moveBall();

    dest.x=game->getBallX();
    dest.y=game->getBallY();

    if(surfaceBall)
      SDL_BlitSurface(surfaceBall,NULL,screen,&dest);
  }
  else
  {
    dest.x=0;
    dest.y=55;

    if(surfaceTitle)
      SDL_BlitSurface(surfaceTitle,NULL,screen,&dest);

    sprintf(text_str,"%s","Press to Start to play...");
    graphics->drawText(screen,text_str,105,210,255,255,0);

    sprintf(text_str,"High Score: %d",high_score);
    graphics->drawText(screen,text_str,2,1,255,255,0);

    if(game->getGameOver())
    {
      sprintf(text_str,"%s","Game Over!");
      graphics->drawText(screen,text_str,130,175,255,0,0);

      sprintf(text_str,"Score: %3d",score);
      graphics->drawText(screen,text_str,268,1,255,255,0);
    }
    else
    {
      sprintf(text_str,"%s","(c) Costa Constantinou 2020");
      graphics->drawText(screen,text_str,170,1,255,255,0);
    }
  }
}

void updateGame()
{
  joystick->processEvents();
  processJoystick();
}

int main(int argc, char *argv[])
{
  if(SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO | SDL_INIT_AUDIO)<0)
		return 0;

  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen==NULL)
    return 0;

  initGame();

  const int GAME_FPS=60;
  Uint32 start_time;

  while(!done)
	{
    start_time=SDL_GetTicks();
    updateGame();
    drawGame();

    SDL_Flip(screen);

    // set FPS
    if(1000/GAME_FPS>SDL_GetTicks()-start_time)
      SDL_Delay(1000/GAME_FPS-(SDL_GetTicks()-start_time));
	}

  endGame();

  SDL_Quit();

  return 1;
}

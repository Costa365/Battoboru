#ifndef _GAME_
#define _GAME_

#define BAT_START 3
#define BAT_LIMIT 275
#define BALL_X_LIMIT 310
#define BALL_Y_BOTTOM_LIMIT 230
#define BALL_Y_TOP_LIMIT 14
#define BALL_MOVE_LEFT 0
#define BALL_MOVE_RIGHT 1
#define BALL_MOVE_UP 0
#define BALL_MOVE_DOWN 1

class Game   
{
public:
  Game();
  int check_game_over();
  void moveBatLeft(int amount);
  void moveBatRight(int amount);
  void moveBallLeft(int amount);
  void moveBallRight(int amount);
  void moveBallDown(int amount);
  void moveBallUp(int amount);
  void setBatX(int pos);
  void setBallX(int pos);
  int getBatX();
  int getBallX();
  void setBatY(int pos);
  void setBallY(int pos);
  int getBatY();
  int getBallY();
  void setGameOver(int val);
  void setInPlay(int val);
  int getGameOver();
  int getInPlay();
  int hasBallHitWall();
  int hasBallHitBottom();
  int hasBallHitTop();
  void setBallVerticalMovement(int direction);
  void setBallHorizontalMovement(int direction);
  int getBallVerticalMovement();
  int getBallHorizontalMovement();

private:
  int in_play;
  int game_over;
  int bat_x;
  int ball_x;
  int bat_y;
  int ball_y;
  int ball_move_horiz;
  int ball_move_vert;
};
 
#endif
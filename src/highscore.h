#ifndef _HIGH_SCORE_
#define _HIGH_SCORE_

class HighScore   
{                

public:
  HighScore(const char *file);
  void writeHighScore(int score);
  int readHighScore();

private:
  const char* filename;
};
 
#endif
#include "highscore.h"

#include <iostream>
#include <fstream>
 
HighScore::HighScore(const char *file)
{
  filename = file;
}

void HighScore::writeHighScore(int score)
{
  std::ofstream ofs(filename, std::ios_base::out | std::ios::trunc );
  ofs << score << '\n';
  ofs.close();
}

int HighScore::readHighScore()
{
 try
  {
    std::ifstream ofs(filename, std::ios_base::in);

    int scr = 0;
    ofs >> scr;

    return scr;
  }
  catch (int)
  {
    return 0;
  }
}
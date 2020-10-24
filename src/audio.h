#ifndef _AUDIO_
#define _AUDIO_

#include <SDL/SDL_mixer.h>
#include <iostream>
#include <vector>

class Audio   
{
public:
  Audio();
  ~Audio();
  void addSound(char const *filePath);
  void playSound(int i);

private:
    std::vector<Mix_Chunk*> sounds;
};
 
#endif
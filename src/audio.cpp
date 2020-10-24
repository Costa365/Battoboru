#include "audio.h"

Audio::Audio()
{
  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16, MIX_DEFAULT_CHANNELS, 1024);
}

Audio::~Audio()
{
  Mix_HaltChannel(-1);
  for (int i=0; i < sounds.size(); i++) {
    Mix_FreeChunk(sounds[i]); 
  }
  
  Mix_CloseAudio();
}

void Audio::addSound(char const *filePath)
{
  Mix_Chunk *sound;
  sound=Mix_LoadWAV(filePath);

  sounds.push_back(sound);
}

void Audio::playSound(int i)
{
  Mix_PlayChannel(1,sounds[i],0);
}

#ifndef _RUMBLE_
#define _RUMBLE_

#include <shake.h>

class Rumble   
{                

public:
  Rumble();
  ~Rumble();
  void playRumble();

private:
  Shake_Device *device;
  Shake_Effect effect;
  int shake_id;

  void initRumble();
  void deinitRumble();
};
 
#endif
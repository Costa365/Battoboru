#include "rumble.h"
 
Rumble::Rumble()
{
  initRumble();
}

Rumble::~Rumble()
{
  deinitRumble();
}
 
void Rumble::initRumble()
{
  Shake_Init();

	if (Shake_NumOfDevices() > 0)
	{
		this->device = Shake_Open(0);

		Shake_InitEffect(&effect, SHAKE_EFFECT_PERIODIC);
		effect.u.periodic.waveform = SHAKE_PERIODIC_SINE;
		effect.u.periodic.period	= 0.1*0x100;
		effect.u.periodic.magnitude	= 0x6000;
		effect.u.periodic.envelope.attackLength	= 0x100;
		effect.u.periodic.envelope.attackLevel	= 0;
		effect.u.periodic.envelope.fadeLength	= 0x100;
		effect.u.periodic.envelope.fadeLevel = 0;
		effect.direction = 0x4000;
		effect.length	= 500;
		effect.delay	= 0;

		this->shake_id=Shake_UploadEffect(device, &effect);
  }
}

void Rumble::deinitRumble()
{
  Shake_EraseEffect(device, shake_id);
  Shake_Close(device);
	Shake_Quit();
}

void Rumble::playRumble()
{
  Shake_Play(device, shake_id);
}
#include "joystick.h"

Joystick::Joystick()
{
  SDL_JoystickEventState(SDL_ENABLE);
  joystick=SDL_JoystickOpen(0);
  clearJoystickStates();
}

Joystick::~Joystick()
{
  if(SDL_JoystickOpened(0))
    SDL_JoystickClose(joystick);
}

void Joystick::clearJoystickStates()
{
  mainjoystick.j1_left=0;
  mainjoystick.j1_right=0;
  mainjoystick.j1_up=0;
  mainjoystick.j1_down=0;
  mainjoystick.button_l3=0;
  mainjoystick.j2_left=0;
  mainjoystick.j2_right=0;
  mainjoystick.j2_up=0;
  mainjoystick.j2_down=0;
  mainjoystick.button_r3=0;
  mainjoystick.pad_left=0;
  mainjoystick.pad_right=0;
  mainjoystick.pad_up=0;
  mainjoystick.pad_down=0;
  mainjoystick.button_a=0;
  mainjoystick.button_b=0;
  mainjoystick.button_x=0;
  mainjoystick.button_y=0;
  mainjoystick.button_l1=0;
  mainjoystick.button_l2=0;
  mainjoystick.button_r1=0;
  mainjoystick.button_r2=0;
  mainjoystick.button_select=0;
  mainjoystick.button_start=0;
  mainjoystick.button_power=0;
  mainjoystick.button_voldown=0;
  mainjoystick.button_volup=0;
  mainjoystick.escape=0;
  mainjoystick.any=0;
}

void Joystick::processEvents()
{
  SDL_Event event;
  static int joy_pressed=0;
  int state = 0;

  while(SDL_PollEvent(&event))
  {
    if(event.type == SDL_KEYDOWN)
      state = 1;

    switch(event.key.keysym.sym)
    {
      case GCW_BUTTON_LEFT:
        mainjoystick.pad_left = state;
        break;
      case GCW_BUTTON_RIGHT:
        mainjoystick.pad_right = state;
        break;
      case GCW_BUTTON_UP:
        mainjoystick.pad_up = state;
        break;
      case GCW_BUTTON_DOWN:
        mainjoystick.pad_down = state;
        break;
      case GCW_BUTTON_Y:
        mainjoystick.button_y = state;
        break;
      case GCW_BUTTON_X:
        mainjoystick.button_x = state;
        break;
      case GCW_BUTTON_B:
        mainjoystick.button_b = state;
        break;
      case GCW_BUTTON_A:
        mainjoystick.button_a = state;
        break;
      case GCW_BUTTON_L1:
        mainjoystick.button_l1 = state;
        break;
      case GCW_BUTTON_L2:
        mainjoystick.button_l2 = state;
        break;
      case GCW_BUTTON_R1:
        mainjoystick.button_r1 = state;
        break;
      case GCW_BUTTON_R2:
        mainjoystick.button_r2 = state;
        break;
      case GCW_BUTTON_L3:
        mainjoystick.button_l3 = state;
        break;
      case GCW_BUTTON_R3:
        mainjoystick.button_r3 = state;
        break;
      case GCW_BUTTON_SELECT:
        mainjoystick.button_select = state;
        break;
      case GCW_BUTTON_START:
        mainjoystick.button_start = state;
        break;
    }
  }
}

int Joystick::getButtonState(int key)
{
  int state = 0;
  switch(key)
  {
    case GCW_BUTTON_LEFT:
      state = mainjoystick.pad_left;
      break;
    case GCW_BUTTON_RIGHT:
      state = mainjoystick.pad_right;
      break;
    case GCW_BUTTON_UP:
      state = mainjoystick.pad_up;
      break;
    case GCW_BUTTON_DOWN:
      state = mainjoystick.pad_down;
      break;
    case GCW_BUTTON_Y:
      state = mainjoystick.button_y;
      break;
    case GCW_BUTTON_X:
      state = mainjoystick.button_x;
      break;
    case GCW_BUTTON_B:
      state = mainjoystick.button_b;
      break;
    case GCW_BUTTON_A:
      state = mainjoystick.button_a;
      break;
    case GCW_BUTTON_L1:
      state = mainjoystick.button_l1;
      break;
    case GCW_BUTTON_L2:
      state = mainjoystick.button_l2;
      break;
    case GCW_BUTTON_R1:
      state = mainjoystick.button_r1;
      break;
    case GCW_BUTTON_R2:
      state = mainjoystick.button_r2;
      break;
    case GCW_BUTTON_L3:
      state = mainjoystick.button_l3;
      break;
    case GCW_BUTTON_R3:
      state = mainjoystick.button_r3;
      break;
    case GCW_BUTTON_SELECT:
      state = mainjoystick.button_select;
      break;
    case GCW_BUTTON_START:
      state = mainjoystick.button_start;
      break;
  }
  return state;
}
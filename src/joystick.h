#ifndef _JOYSTICK_
#define _JOYSTICK_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#define GCW_BUTTON_UP           SDLK_UP
#define GCW_BUTTON_DOWN         SDLK_DOWN
#define GCW_BUTTON_LEFT         SDLK_LEFT
#define GCW_BUTTON_RIGHT        SDLK_RIGHT
#define GCW_BUTTON_A            SDLK_LCTRL
#define GCW_BUTTON_B            SDLK_LALT
#define GCW_BUTTON_X            SDLK_SPACE
#define GCW_BUTTON_Y            SDLK_LSHIFT
#define GCW_BUTTON_L1           SDLK_TAB
#define GCW_BUTTON_R1           SDLK_BACKSPACE
#define GCW_BUTTON_L2           SDLK_PAGEUP
#define GCW_BUTTON_R2           SDLK_PAGEDOWN
#define GCW_BUTTON_SELECT       SDLK_ESCAPE
#define GCW_BUTTON_START        SDLK_RETURN
#define GCW_BUTTON_L3           SDLK_KP_DIVIDE
#define GCW_BUTTON_R3           SDLK_KP_PERIOD
#define GCW_BUTTON_POWER        SDLK_HOME

#define GCW_JOYSTICK_DEADZONE   1000

struct joystick_state
{
  int j1_left;
  int j1_right;
  int j1_up;
  int j1_down;
  int button_l3;
  int j2_left;
  int j2_right;
  int j2_up;
  int j2_down;
  int button_r3;
  int pad_left;
  int pad_right;
  int pad_up;
  int pad_down;
  int button_a;
  int button_b;
  int button_x;
  int button_y;
  int button_l1;
  int button_l2;
  int button_r1;
  int button_r2;
  int button_select;
  int button_start;
  int button_power;
  int button_voldown;
  int button_volup;
  int escape;
  int any;
};

class Joystick   
{                

public:
    Joystick();
    ~Joystick();

    void processEvents();
    int getButtonState(int key);

private:
    SDL_Joystick* joystick;         
    joystick_state mainjoystick;
    void clearJoystickStates();
};
 
#endif
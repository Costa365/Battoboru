#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

class Graphics   
{
public:
  Graphics();
  void drawLine(SDL_Surface* dst, int x0, int y0, int x1, int y1, Uint32 pixel);
  void drawText(SDL_Surface* dst, char* string, int x, int y, int fR, int fG, int fB);
  void loadImageAplha(SDL_Surface* dst, const char* file, SDL_Surface *&surface);

private:
  TTF_Font* font;
  void putPixel(SDL_Surface *dst, int x, int y, Uint32 pixel);
};
 
#endif
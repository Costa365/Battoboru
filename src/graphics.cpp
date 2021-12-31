#include "graphics.h"
#include <math.h>

Graphics::Graphics()
{
  TTF_Init();
  font=TTF_OpenFont("media/pixelberry.ttf", 8);
}

void Graphics::putPixel(SDL_Surface *dst, int x, int y, Uint32 pixel)
{
  int byteperpixel = dst->format->BytesPerPixel;
  Uint8 *p = (Uint8*)dst->pixels + y * dst->pitch + x * byteperpixel;
  // Adress to pixel
  *(Uint32 *)p = pixel;
}

void Graphics::drawLine(SDL_Surface* dst, int x0, int y0, int x1, int y1, Uint32 pixel)
{
  int i;
  double x = x1 - x0;
  double y = y1 - y0;
  double length = sqrt( x*x + y*y );
  double addx = x / length;
  double addy = y / length;
  x = x0;
  y = y0;

  for ( i = 0; i < length; i += 1) {
    putPixel(dst, x, y, pixel);
    x += addx;
    y += addy;
  }
}

void Graphics::drawRect(SDL_Surface* dst, int x, int y, int w, int h, Uint32 colour)
{
  if(dst)
  {
    SDL_Rect rect;
    
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;

    SDL_FillRect(dst, &rect, colour);
  }
}

void Graphics::drawPanel(SDL_Surface* dst, int x, int y, int w, int h, Uint32 colMain, Uint32 colRight, Uint32 colLeft)
{
  drawRect(dst, x, y, w, h, colMain);
  drawLine(dst, x, y, x+w, y, colLeft);
  drawLine(dst, x, y, x, y+h, colLeft);
  drawLine(dst, x+w, y, x+w, y+h, colRight);
  drawLine(dst, x, y+h, x+w, y+h, colRight);
}

void Graphics::drawText(SDL_Surface* dst, char* string, int x, int y, int fR, int fG, int fB)
{
  if(dst && string && font)
  {
    SDL_Color foregroundColor={fR,fG,fB};
    SDL_Surface *textSurface=TTF_RenderText_Blended(font,string,foregroundColor);
    if(textSurface)
    {
      SDL_Rect textLocation={x,y,0,0};
      SDL_BlitSurface(textSurface,NULL,dst,&textLocation);
      SDL_FreeSurface(textSurface);
    }
  }
}

void Graphics::loadImageAplha(SDL_Surface* dst, const char* file, SDL_Surface *&surface)
{
  SDL_Surface *tmpsurface;

  tmpsurface=IMG_Load(file);
  if(tmpsurface)
  {
    surface=SDL_CreateRGBSurface(SDL_SRCCOLORKEY, tmpsurface->w, tmpsurface->h, 16, 0,0,0,0);
    SDL_BlitSurface(tmpsurface,NULL,surface,NULL);
    SDL_SetColorKey(surface,SDL_SRCCOLORKEY,SDL_MapRGB(dst->format,0,0,0));
    SDL_FreeSurface(tmpsurface);
  }
}

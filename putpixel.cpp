/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void    draw_function(SDL_Surface **ecran, double k)
{
    int x[100];

    x[1] = 10;
    putpixel(*ecran, 1, (WIN_Y - 1) - x[1], 0xFFFFFF);
    for (int i = 2; i < 100; i++)
    {
        x[i] = (k * x[i - 1] * (1000 - x[i - 1])) / 1000;
        putpixel(*ecran, i, (WIN_Y - 1) - x[i], 0xFFFFFF);
    }
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

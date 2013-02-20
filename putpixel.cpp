/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void    draw_function(SDL_Surface **ecran)
{

}

void    draw_axes(SDL_Surface **ecran)
{
    for (int i = 0; i < WIN_X; i++)
    {
        putpixel(*ecran, i, WIN_Y / 2, 0xFFFFFF); //Drawing X Axe
    }
    for (int i = 0; i < WIN_Y; i++)
    {
        putpixel(*ecran, WIN_X / 2, i, 0xFFFFFF); // Drawing Y Axe
    }
    for(int i = 7; i != 0; i--)
    {
        putpixel(*ecran, (WIN_X / 2) - i, i, 0xFFFFFF); // Drawing X left-arrow
        putpixel(*ecran, (WIN_X / 2) + i, i, 0xFFFFFF); // Drawing X right-arrow
        putpixel(*ecran, WIN_X - i - 1, (WIN_Y / 2) - i, 0xFFFFFF); // Drawing Y up-arrow
        putpixel(*ecran, WIN_X - i - 1, (WIN_Y / 2) + i, 0xFFFFFF); // Drawing Y down-arrow
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

/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void    draw_axes(SDL_Surface **ecran)
{
    for (int x = 0; x < WIN_X - 1; x++)
    {
        putpixel(*ecran, x, WIN_Y - 1, 0xFFFFFF);
    }
    for (int y = 0; y < WIN_Y; y++)
    {
        putpixel(*ecran, 0, y, 0xFFFFFF);
    }
}

void    draw_function(SDL_Surface **ecran, double k)
{
    int i = 0;
    int t = 0;
    int x[100];

    x[i++] = 0;
    putpixel(*ecran, 0, WIN_Y, 0x1E7FCB);
    x[i] = 10;
    putpixel(*ecran, 10, WIN_Y - x[i], 0x1E7FCB);
    drawLine(*ecran, 0, WIN_Y, 10, WIN_Y - x[i++], 0x1E7FCB);
    for (int j = 20; j < 990; j += 10)
    {
        x[i] = (k * x[i - 1] * (WIN_Y - x[i - 1])) / 1000;
        putpixel(*ecran, j, WIN_Y - x[i], 0x1E7FCB);
        drawLine(*ecran, j - 10, WIN_Y - x[i - 1], j, WIN_Y - x[i], 0x1E7FCB);
        i++;
        t = j;
    }
    for (int j = 990; j < 1010; j += 10)
    {
        x[i] = (k * x[i - 1] * (WIN_Y - x[i - 1])) / 1000;
        putpixel(*ecran, j, WIN_Y - x[i], 0x1E7FCB);
        drawLine(*ecran, j - 10, (WIN_Y - 1) - x[i - 1], j, WIN_Y - x[i], 0x1E7FCB);
        i++;
    }
    //t += 10;

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

void drawLine(SDL_Surface *ecran, int x0, int y0, int x1, int y1, Uint32 pixel)
{
    int i;
    double x = x1 - x0;
    double y = y1 - y0;
    double length = sqrt( x*x + y*y );
    double addx = x / length;
    double addy = y / length;
    x = x0;
    y = y0;

    for ( i = 0; i < length; i++)
        {
            putpixel(ecran, x, y, pixel);
            x += addx;
            y += addy;
        }
}

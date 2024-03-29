/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void    draw_axes(SDL_Surface **ecran)
{
    char number[5];

    SDL_Surface *grad = NULL;
    SDL_Rect pos;
    SDL_Color white = {255, 255, 255};

    TTF_Font *font = NULL;
    font = TTF_OpenFont("arial.ttf", 10);

        sprintf(number, "0");
        grad = TTF_RenderText_Solid(font, number, white);
        pos.x = 7;
        pos.y = WIN_Y - 17;
        SDL_BlitSurface(grad, NULL, *ecran, &pos);

    for (int x = 100; x < WIN_X; x += 100)
    {
        sprintf(number, "%d", x);
        grad = TTF_RenderText_Solid(font, number, white);
        pos.x = x;
        pos.y = WIN_Y - 17;
        SDL_BlitSurface(grad, NULL, *ecran, &pos);
    }
    for (int y = WIN_Y; y > 0; y -= 100)
    {
        sprintf(number, "%d", y);
        grad = TTF_RenderText_Solid(font, number, white);
        pos.x = 7;
        pos.y = WIN_Y - y;
        SDL_BlitSurface(grad, NULL, *ecran, &pos);
    }
    for (int x = 0; x < WIN_X - 1; x++)
    {
        putpixel(*ecran, x, WIN_Y - 1, 0xFFFFFF);
    }
    for (int y = 0; y < WIN_Y; y++)
    {
        putpixel(*ecran, 0, y, 0xFFFFFF);
    }

    TTF_CloseFont(font);
}

void    draw_function1(SDL_Surface **ecran, double k)
{
    int i = 0;
    double x[100];

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
    }
    for (int j = 990; j < 1000; j += 10)
    {
        x[i] = (k * x[i - 1] * (WIN_Y - x[i - 1])) / 1000;
        putpixel(*ecran, j, WIN_Y - x[i], 0x1E7FCB);
        drawLine(*ecran, j - 10, WIN_Y - x[i - 1], j, WIN_Y - x[i], 0x1E7FCB);
        i++;
    }
}

void    draw_function2(SDL_Surface **ecran, int imin, int imax)
{
    double x;

    x = 10;
    for (double k = 1.0; k <= 4.0; k += 0.01)
    {
        for (int i = 0; i <= imin; i++)
        {
            x = ((k * x * (WIN_Y - x)) / 1000);
        }
        for (int i = imin; i < imax; i++)
        {
            x = ((k * x * (WIN_Y - x)) / 1000);
            putpixel(*ecran, (k - 1) * 333, WIN_Y - x, 0xFFFFFF);
        }
        x = 10;
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

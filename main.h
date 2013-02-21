/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cmath>
#include <SDL.h>

#define WIN_X 1000
#define WIN_Y 1000

void    pause();
void    SDL_func(SDL_Surface **ecran);
void    putpixel(SDL_Surface *surface, int x, int y, Uint32 color);
void    draw_axes(SDL_Surface **ecran);
void    drawLine(SDL_Surface *ecran, int x0, int y0, int x1, int y1, Uint32 pixel);
void    draw_function1(SDL_Surface **ecran, double k);
void    draw_function2(SDL_Surface **ecran, int imin, int imax);

#endif // MAIN_H_INCLUDED

/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <SDL.h>

#define WIN_X 1000
#define WIN_Y 1000

void    pause();
void    SDL_func(SDL_Surface **ecran);
void    putpixel(SDL_Surface *surface, int x, int y, Uint32 color);
void    draw_function(SDL_Surface **ecran, double k);

#endif // MAIN_H_INCLUDED

/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define WIN_X 800
#define WIN_Y 600

#include <iostream>
#include <SDL.h>

void    pause();
void    SDL_func(SDL_Surface **ecran);
void    putpixel(SDL_Surface *surface, int x, int y, Uint32 color);
void    draw_axes(SDL_Surface **surface);
void    draw_function(SDL_Surface **ecran);

#endif // MAIN_H_INCLUDED

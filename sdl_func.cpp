/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void    SDL_func(SDL_Surface **ecran)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    *ecran = SDL_SetVideoMode(WIN_X, WIN_Y, 32, SDL_HWSURFACE);
    if (*ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vid�o : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);

    SDL_WM_SetCaption("106bombyx", NULL);
}

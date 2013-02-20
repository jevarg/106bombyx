/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}

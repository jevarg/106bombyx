/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    SDL_Surface *ecran = NULL;

    SDL_func(&ecran);
    SDL_Flip(ecran);
    pause();
    SDL_Quit();
    return (EXIT_SUCCESS);
}

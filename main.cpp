/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    //if (argc > 1)
    //{
        SDL_Surface *ecran = NULL;
        SDL_func(&ecran);
        draw_function(&ecran, 1);
        //draw_function(&ecran, atoi(argv[1]));
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    //}
    return (EXIT_SUCCESS);
}

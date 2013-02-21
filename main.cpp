/*
=====================================
===106bombyx by gravie_j & delafo_===
=====================================
*/

#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (atof(argv[1]) <= 1 || atof(argv[1]) >= 4)
        {
            freopen("CON", "w", stdout);
            cout<<"Le parametre k doit etre un nombre compris entre 1 et 4 EXCLUS !"<<endl;
            fclose(stdout);
            return (EXIT_FAILURE);
        }
        SDL_Surface *ecran = NULL;
        SDL_func(&ecran);
        draw_axes(&ecran);
        draw_function1(&ecran, atof(argv[1]));
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    }
    else if (1)
    {
        SDL_Surface *ecran = NULL;
        SDL_func(&ecran);
        //draw_function2(&ecran, atoi(argv[1]), atoi(argv[2]));
        draw_function2(&ecran, 10000, 10010);
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    }
    return (EXIT_SUCCESS);
}

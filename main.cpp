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
        draw_function(&ecran, atof(argv[1]));
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    }
    else if (argc == 3)
    {
        return (EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}

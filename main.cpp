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
        if (atof(argv[1]) < 1 || atof(argv[1]) > 4)
        {
            freopen("CON", "w", stdout);
            cout<<"k doit etre compris entre 1 et 4 inclus.";
            fclose(stdout);
            return (EXIT_FAILURE);
        }
        SDL_Surface *ecran = NULL;
        SDL_func(&ecran);
        draw_function1(&ecran, atof(argv[1]));
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    }
    else if (argc > 2)
    {
        if (atoi(argv[1]) >= atoi(argv[2]))
        {
            freopen("CON", "w", stdout);
            cout<<"imin doit etre strictement inferieur a imax."<<endl;
            fclose(stdout);
            return (EXIT_FAILURE);
        }
        SDL_Surface *ecran = NULL;
        SDL_func(&ecran);
        draw_function2(&ecran, atoi(argv[1]), atoi(argv[2]));
        SDL_Flip(ecran);
        pause();
        SDL_Quit();
    }
    else
    {
        freopen("CON", "w", stdout);
        cout<<"Utilisation: 106bombyx.exe k OU 106bombyx.exe imin imax"<<endl;
        fclose(stdout);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

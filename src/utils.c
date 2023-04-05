#include <SDL.h>
#include <SDL_ttf.h>

void exitWithError(char *filename, int lineError)
{
    SDL_Log("Error in file %s at line %d : %s", filename, lineError, SDL_GetError());
    TTF_Quit();
    SDL_Quit();
    exit(1);
}
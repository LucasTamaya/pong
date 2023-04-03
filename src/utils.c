#include <SDL.h>

void exitWithError(char *filename, int lineError)
{
    SDL_Log("Error in file %s at line %d : %s", filename, lineError, SDL_GetError());
    SDL_Quit();
    exit(1);
}
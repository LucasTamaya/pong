#include "rendering.h"
#include "constants.h"

void renderGame()
{
    SDL_SetRenderDrawColor(renderer, 94, 0, 188, 255);
    SDL_RenderFillRect(renderer, &padLeft);
    SDL_RenderFillRect(renderer, &padRight);
    SDL_RenderFillRect(renderer, &ball);
}
#include "rendering.h"
#include "constants.h"
#include "utils.h"

void renderGame(SDL_Renderer *renderer, SDL_Rect *padLeft, SDL_Rect *padRight, SDL_Rect *ball)
{
    SDL_SetRenderDrawColor(renderer, 94, 0, 188, 255);
    SDL_RenderFillRect(renderer, padLeft);
    SDL_RenderFillRect(renderer, padRight);
    SDL_RenderFillRect(renderer, ball);
}

void renderPad(SDL_Renderer *renderer, SDL_Rect *pad, SDL_Color color)
{
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, 11);

    if (SDL_RenderFillRect(renderer, pad) != 0)
        exitWithError(__FILE__, 33);

    SDL_RenderPresent(renderer);
}
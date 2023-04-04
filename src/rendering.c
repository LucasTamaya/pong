#include "rendering.h"
#include "constants.h"
#include "utils.h"
#include "game.h"

void renderGame(SDL_Renderer *renderer, SDL_FRect *padLeft, SDL_FRect *padRight, SDL_FRect *ball, SDL_Color color, int isGameStarted)
{
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, 11);

    if (isGameStarted)
        handleBallBounces(ball, padLeft, padRight);

    if (SDL_RenderFillRectF(renderer, padLeft) != 0)
        exitWithError(__FILE__, 10);
    if (SDL_RenderFillRectF(renderer, padRight) != 0)
        exitWithError(__FILE__, 12);
    if (SDL_RenderFillRectF(renderer, ball) != 0)
        exitWithError(__FILE__, 14);
}
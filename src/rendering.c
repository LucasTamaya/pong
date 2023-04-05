#include "rendering.h"
#include "constants.h"
#include "utils.h"
#include "game.h"

SDL_Rect scoreLeftRect = {100, 100, 100, 100};
SDL_Rect scoreRightRect = {WINDOW_WIDTH - 200, 100, 100, 100};

void renderGame(SDL_Renderer *renderer, SDL_FRect *padLeft, SDL_FRect *padRight, SDL_FRect *ball, SDL_Color color, int isGameStarted)
{
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, __LINE__);

    if (isGameStarted)
    {
        handleBallBounces(ball, padLeft, padRight);
        handleScore(ball, &scoreLeft, &scoreRight, renderer, color);
    }

    // Draw pads and ball
    if (SDL_RenderFillRectF(renderer, padLeft) != 0)
        exitWithError(__FILE__, __LINE__);
    if (SDL_RenderFillRectF(renderer, padRight) != 0)
        exitWithError(__FILE__, __LINE__);
    if (SDL_RenderFillRectF(renderer, ball) != 0)
        exitWithError(__FILE__, __LINE__);
    if (SDL_RenderCopy(renderer, textureScoreLeft, NULL, &scoreLeftRect) != 0)
        exitWithError(__FILE__, __LINE__);
    if (SDL_RenderCopy(renderer, textureScoreRight, NULL, &scoreRightRect) != 0)
        exitWithError(__FILE__, __LINE__);
}
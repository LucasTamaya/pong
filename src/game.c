#include <stdio.h>

#include "game.h"
#include "constants.h"
#include "utils.h"

// Ball movement
// void updateBallPosition(void)
// {
//     if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
//         exitWithError(__FILE__, 11);

//     if (SDL_RenderFillRect(renderer, &ball) != 0)
//         exitWithError(__FILE__, 33);

//     SDL_RenderPresent(renderer);
// }

// void startGame(void)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         ball.x += 2;
//         ball.y += 2;
//         updateBallPosition();
//     }
// }

// Pad movement
void updatePadPosition(SDL_Rect *pad)
{
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, 11);

    if (SDL_RenderFillRect(renderer, pad) != 0)
        exitWithError(__FILE__, 33);

    SDL_RenderPresent(renderer);
}

void handlePadMovement(SDL_Rect *pad, char *direction)
{
    if (SDL_strcmp(direction, "UP") == 0 && pad->y > 0)
    {
        pad->y -= 10;
        updatePadPosition(pad);
    }

    if (SDL_strcmp(direction, "DOWN") == 0 && pad->y < WINDOW_HEIGHT - pad->h)
    {
        pad->y += 10;
        updatePadPosition(pad);
    }
}
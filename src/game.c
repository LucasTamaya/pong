#include <stdio.h>

#include "game.h"
#include "constants.h"
#include "utils.h"
#include "rendering.h"

// void handlePadMovement(SDL_Rect *pad, char *direction)
// {
//     if (SDL_strcmp(direction, "UP") == 0 && pad->y > 0)
//     {
//         pad->y -= 10;
//         renderPad(renderer, pad, color);
//     }

//     if (SDL_strcmp(direction, "DOWN") == 0 && pad->y < WINDOW_HEIGHT - pad->h)
//     {
//         pad->y += 10;
//         renderPad(pad);
//     }
// }

void movePadToTop(SDL_Rect *pad, SDL_Renderer *renderer, SDL_Color color)
{
    if (pad->y > 0)
    {
        pad->y -= 10;
        renderPad(renderer, pad, color);
    }
}

void movePadToBottom(SDL_Rect *pad, SDL_Renderer *renderer, SDL_Color color)
{
    if (pad->y < WINDOW_HEIGHT - pad->h)
    {
        pad->y += 10;
        renderPad(renderer, pad, color);
    }
}
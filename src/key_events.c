#include "key_events.h"
#include "constants.h"
#include "game.h"

void handleKeyEvents(SDL_Renderer *renderer, SDL_Event *event, SDL_Rect *padLeft, SDL_Rect *padRight, SDL_Color color, int *isGameStarted)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_z:
        movePadToTop(padLeft, renderer, color);
        break;

    case SDLK_s:
        movePadToBottom(padLeft, renderer, color);
        break;

    case SDLK_UP:
        movePadToTop(padRight, renderer, color);
        break;

    case SDLK_DOWN:
        movePadToBottom(padRight, renderer, color);
        break;

    case SDLK_SPACE:
        *isGameStarted = 1;
        break;

    default:
        break;
    }
}
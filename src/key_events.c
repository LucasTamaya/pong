#include "key_events.h"
#include "constants.h"
#include "game.h"

void handleKeyEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_z:
        handlePadMovement(&padLeft, "UP");
        break;

    case SDLK_s:
        handlePadMovement(&padLeft, "DOWN");
        break;

    case SDLK_UP:
        handlePadMovement(&padRight, "UP");
        break;

    case SDLK_DOWN:
        handlePadMovement(&padRight, "DOWN");
        break;

    case SDLK_SPACE:
        gameStarted = 1;
        // startGame();
        break;

    default:
        break;
    }
}
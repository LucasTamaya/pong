#include <stdio.h>

#include "game.h"
#include "constants.h"
#include "utils.h"
#include "rendering.h"

float ballXSpeedMove = 0.1f;
float ballYSpeedMove = 0.1f;

void movePadToTop(SDL_FRect *pad, SDL_Renderer *renderer, SDL_Color color)
{
    if (pad->y > 0)
    {
        pad->y -= 10;
        renderPad(renderer, pad, color);
    }
}

void movePadToBottom(SDL_FRect *pad, SDL_Renderer *renderer, SDL_Color color)
{
    if (pad->y < WINDOW_HEIGHT - pad->h)
    {
        pad->y += 10;
        renderPad(renderer, pad, color);
    }
}

void handleBallBounces(SDL_FRect *ball)
{
    SDL_bool ballBounceOnWindowTop = ball->y < 0;
    SDL_bool ballBounceOnWindowBottom = ball->y > WINDOW_HEIGHT - ball->h;
    SDL_bool ballBounceOnWindowLeft = ball->x < 0;
    SDL_bool ballBounceOnWindowRight = ball->x > WINDOW_WIDTH - ball->w;

    ball->x += ballXSpeedMove;
    ball->y += ballYSpeedMove;

    if (ballBounceOnWindowTop)
    {
        ball->y += 1;
        ballYSpeedMove = ballYSpeedMove * -1;
    }

    if (ballBounceOnWindowBottom)
    {
        ball->y -= 1;
        ballYSpeedMove = ballYSpeedMove * -1;
    }

    if (ballBounceOnWindowLeft)
    {
        ball->x += 1;
        ballXSpeedMove = ballXSpeedMove * -1;
    }

    if (ballBounceOnWindowRight)
    {
        ball->x -= 1;
        ballXSpeedMove = ballXSpeedMove * -1;
    }
}
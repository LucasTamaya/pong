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
        pad->y -= 10;
}

void movePadToBottom(SDL_FRect *pad, SDL_Renderer *renderer, SDL_Color color)
{
    if (pad->y < WINDOW_HEIGHT - pad->h)
        pad->y += 10;
}

void reverseBallSpeedMove(float *ballSpeedMove)
{
    *ballSpeedMove *= -1;
}

void handleBallBounceOnWindow(SDL_FRect *ball)
{
    SDL_bool ballBounceOnWindowTop = ball->y < 0;
    SDL_bool ballBounceOnWindowBottom = ball->y > WINDOW_HEIGHT - ball->h;

    if (ballBounceOnWindowTop)
    {
        ball->y += 1;
        reverseBallSpeedMove(&ballYSpeedMove);
    }

    if (ballBounceOnWindowBottom)
    {
        ball->y -= 1;
        reverseBallSpeedMove(&ballYSpeedMove);
    }
}

void handleBallBounceOnPads(SDL_FRect *ball, SDL_FRect *padLeft, SDL_FRect *padRight)
{
    SDL_bool ballBounceOnPadLeft = ball->x < padLeft->x + PAD_WIDTH && ball->y > padLeft->y && ball->y < padLeft->y + PAD_HEIGHT;
    SDL_bool ballBounceOnPadRight = ball->x + ball->w > padRight->x && ball->y > padRight->y && ball->y < padRight->y + PAD_HEIGHT;

    if (ballBounceOnPadLeft || ballBounceOnPadRight)
        reverseBallSpeedMove(&ballXSpeedMove);
}

void handleBallBounces(SDL_FRect *ball, SDL_FRect *padLeft, SDL_FRect *padRight)
{
    ball->x += ballXSpeedMove;
    ball->y += ballYSpeedMove;
    handleBallBounceOnWindow(ball);
    handleBallBounceOnPads(ball, padLeft, padRight);
}
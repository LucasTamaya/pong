#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#include "constants.h"
#include "utils.h"
#include "key_events.h"
#include "rendering.h"

void closeProgram(SDL_Renderer *renderer, SDL_Window *window);
void createRect(SDL_Rect *rect, int x, int y, int w, int h);

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect padLeft = {};
    SDL_Rect padRight = {};
    SDL_Rect ball = {};
    SDL_Color color = {94, 0, 188, 255};
    int isProgramLaunched = 1;
    int isGameStarted = 0;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exitWithError(__FILE__, 28);

    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
        exitWithError(__FILE__, 31);

    createRect(&padLeft, 20, (WINDOW_HEIGHT - PAD_HEIGHT) / 2, PAD_WIDTH, PAD_HEIGHT);
    createRect(&padRight, WINDOW_WIDTH - PAD_WIDTH - 20, (WINDOW_HEIGHT - PAD_HEIGHT) / 2, PAD_WIDTH, PAD_HEIGHT);
    createRect(&ball, (WINDOW_WIDTH - BALL_WIDTH) / 2, (WINDOW_HEIGHT - BALL_HEIGHT) / 2, BALL_WIDTH, BALL_HEIGHT);

    while (isProgramLaunched)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                handleKeyEvents(renderer, &event, &padLeft, &padRight, color, &isGameStarted);
                break;

            case SDL_QUIT:
                isProgramLaunched = 0;
                break;

            default:
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderGame(renderer, &padLeft, &padRight, &ball);

        if (isGameStarted)
        {
            ball.x += 2;
            ball.y += 2;
            if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
                exitWithError(__FILE__, 11);

            if (SDL_RenderFillRect(renderer, &ball) != 0)
                exitWithError(__FILE__, 33);

            SDL_RenderPresent(renderer);
        }
        SDL_RenderPresent(renderer);
    }

    closeProgram(renderer, window);
    return 0;
}

void closeProgram(SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void createRect(SDL_Rect *rect, int x, int y, int w, int h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#include "constants.h"
#include "utils.h"
#include "key_events.h"
#include "rendering.h"

void closeProgram(void);

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect padLeft = {};
SDL_Rect padRight = {};
SDL_Rect ball = {};
SDL_Color color = {94, 0, 188, 255};
int gameStarted = 0;

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exitWithError(__FILE__, 28);

    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
        exitWithError(__FILE__, 31);

    padLeft.w = PAD_WIDTH;
    padLeft.h = PAD_HEIGHT;
    padLeft.x = 20;
    padLeft.y = (WINDOW_HEIGHT - PAD_HEIGHT) / 2;

    padRight.w = PAD_WIDTH;
    padRight.h = PAD_HEIGHT;
    padRight.x = WINDOW_WIDTH - PAD_WIDTH - 20;
    padRight.y = (WINDOW_HEIGHT - PAD_HEIGHT) / 2;

    ball.w = BALL_WIDTH;
    ball.h = BALL_HEIGHT;
    ball.x = (WINDOW_WIDTH - BALL_WIDTH) / 2;
    ball.y = (WINDOW_HEIGHT - BALL_HEIGHT) / 2;

    SDL_bool programLaunched = 1;

    while (programLaunched)
    {
        SDL_Event event;
        // détecte tous les éléments lorsque le programme est lancé
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                handleKeyEvents(&event);
                break;

            case SDL_QUIT:
                programLaunched = 0;
                break;

            default:
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderGame();

        if (gameStarted)
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

    closeProgram();
    return 0;
}

void closeProgram(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "constants.h"
#include "utils.h"
#include "key_events.h"
#include "rendering.h"

void closeProgram(SDL_Texture *texture, SDL_Surface *surface, TTF_Font *font, SDL_Renderer *renderer, SDL_Window *window);
void createRect(SDL_FRect *rect, float x, float y, float w, float h);

TTF_Font *font = NULL;
SDL_Surface *surfaceScoreLeft = NULL;
SDL_Texture *textureScoreLeft = NULL;
SDL_Surface *surfaceScoreRight = NULL;
SDL_Texture *textureScoreRight = NULL;
int scoreLeft = 0;
int scoreRight = 0;

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_FRect padLeft = {};
    SDL_FRect padRight = {};
    SDL_FRect ball = {};
    SDL_Color color = {94, 0, 188, 255};
    int isProgramLaunched = 1;
    int isGameStarted = 0;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exitWithError(__FILE__, __LINE__);

    if (TTF_Init() != 0)
        exitWithError(__FILE__, __LINE__);

    font = TTF_OpenFont(FONT_FILE_PATH, 25);
    if (font == NULL)
        exitWithError(__FILE__, __LINE__);

    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
        exitWithError(__FILE__, __LINE__);

    createRect(&padLeft, 20, (WINDOW_HEIGHT - PAD_HEIGHT) / 2, PAD_WIDTH, PAD_HEIGHT);
    createRect(&padRight, WINDOW_WIDTH - PAD_WIDTH - 20, (WINDOW_HEIGHT - PAD_HEIGHT) / 2, PAD_WIDTH, PAD_HEIGHT);
    createRect(&ball, (WINDOW_WIDTH - BALL_WIDTH) / 2, (WINDOW_HEIGHT - BALL_HEIGHT) / 2, BALL_WIDTH, BALL_HEIGHT);

    // Scores
    surfaceScoreLeft = TTF_RenderText_Solid(font, "0", color);
    if (surfaceScoreLeft == NULL)
        exitWithError(__FILE__, __LINE__);

    textureScoreLeft = SDL_CreateTextureFromSurface(renderer, surfaceScoreLeft);
    if (textureScoreLeft == NULL)
        exitWithError(__FILE__, __LINE__);

    surfaceScoreRight = TTF_RenderText_Solid(font, "0", color);
    if (surfaceScoreRight == NULL)
        exitWithError(__FILE__, __LINE__);

    textureScoreRight = SDL_CreateTextureFromSurface(renderer, surfaceScoreRight);
    if (textureScoreRight == NULL)
        exitWithError(__FILE__, __LINE__);

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
        renderGame(renderer, &padLeft, &padRight, &ball, color, isGameStarted);
        SDL_RenderPresent(renderer);
    }

    closeProgram(textureScoreLeft, surfaceScoreLeft, font, renderer, window);
    return 0;
}

void closeProgram(SDL_Texture *texture, SDL_Surface *surface, TTF_Font *font, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void createRect(SDL_FRect *rect, float x, float y, float w, float h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}
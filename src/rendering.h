#ifndef RENDERING_H_
#define RENDERING_H_

#include <SDL.h>
#include <SDL_ttf.h>

void renderGame(SDL_Renderer *renderer, SDL_FRect *padLeft, SDL_FRect *padRight, SDL_FRect *ball, SDL_Color color, int isGameStarted);

#endif
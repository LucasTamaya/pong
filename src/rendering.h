#ifndef RENDERING_H_
#define RENDERING_H_

#include <SDL.h>

void renderGame(SDL_Renderer *renderer, SDL_FRect *padLeft, SDL_FRect *padRight, SDL_FRect *ball, SDL_Color color, int isGameStarted);
void renderPad(SDL_Renderer *renderer, SDL_FRect *pad, SDL_Color color);

#endif
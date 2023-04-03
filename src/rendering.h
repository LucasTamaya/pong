#ifndef RENDERING_H_
#define RENDERING_H_

#include <SDL.h>

void renderGame(SDL_Renderer *renderer, SDL_Rect *padLeft, SDL_Rect *padRight, SDL_Rect *ball);
void renderPad(SDL_Renderer *renderer, SDL_Rect *pad, SDL_Color color);

#endif
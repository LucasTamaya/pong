#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>

void movePadToTop(SDL_Rect *pad, SDL_Renderer *renderer, SDL_Color color);
void movePadToBottom(SDL_Rect *pad, SDL_Renderer *renderer, SDL_Color color);

#endif
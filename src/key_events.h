#ifndef KEY_EVENTS_H_
#define KEY_EVENTS_H_

#include <SDL.h>

void handleKeyEvents(SDL_Renderer *renderer, SDL_Event *event, SDL_FRect *padLeft, SDL_FRect *padRight, SDL_Color color, int *isGameStarted);

#endif
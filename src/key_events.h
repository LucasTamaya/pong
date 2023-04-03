#ifndef KEY_EVENTS_H_
#define KEY_EVENTS_H_

#include <SDL.h>

void handleKeyEvents(SDL_Renderer *renderer, SDL_Event *event, SDL_Rect *padLeft, SDL_Rect *padRight, SDL_Color color, int *isGameStarted);

#endif
#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>

void movePadToTop(SDL_FRect *pad, SDL_Renderer *renderer, SDL_Color color);
void movePadToBottom(SDL_FRect *pad, SDL_Renderer *renderer, SDL_Color color);
void reverseBallSpeedMove(float *ballSpeedMove);
void handleBallBounceOnWindow(SDL_FRect *ball);
void handleBallBounceOnPads(SDL_FRect *ball, SDL_FRect *padLeft, SDL_FRect *padRight);
void handleBallBounces(SDL_FRect *ball, SDL_FRect *padLeft, SDL_FRect *padRight);

#endif
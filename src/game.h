#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>

void startGame(void);
void updateBallPosition(void);
void updatePadPosition(SDL_Rect *pad);
void handlePadMovement(SDL_Rect *pad, char *direction);

#endif
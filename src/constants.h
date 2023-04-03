#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PAD_WIDTH 20
#define PAD_HEIGHT 100
#define BALL_WIDTH 20
#define BALL_HEIGHT 20

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Rect padLeft;
extern SDL_Rect padRight;
extern SDL_Rect ball;
extern SDL_Color color;
extern int gameStarted;

#endif
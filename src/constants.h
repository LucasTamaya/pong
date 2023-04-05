#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PAD_WIDTH 20
#define PAD_HEIGHT 100
#define BALL_WIDTH 20
#define BALL_HEIGHT 20
#define FONT_FILE_PATH "C:/Users/lucas/OneDrive/Documents/informatique/C/pong_sdl/font/Lato-Regular.ttf"

#include <SDL_ttf.h>

extern SDL_Surface *surfaceScoreLeft;
extern SDL_Texture *textureScoreLeft;
extern SDL_Surface *surfaceScoreRight;
extern SDL_Texture *textureScoreRight;
extern TTF_Font *font;
extern int scoreLeft;
extern int scoreRight;

#endif
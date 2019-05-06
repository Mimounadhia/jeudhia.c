#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"
#include "ennemi.h"
#include "hero.h"
typedef struct minimap
{
	SDL_Surface *miniImg;
	SDL_Rect miniPos;

}minimap;


struct Background{
	SDL_Surface *backgroundImg;
	SDL_Rect backgroundPos;

};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);
int loadBackground2(minimap *m);
void blitmini(minimap *Backg,SDL_Surface *screen);
void init_minimap(minimap *m);
void free_minimap(minimap *m);
#endif

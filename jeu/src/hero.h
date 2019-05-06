#ifndef Hero_H
#define Hero_H
#include <SDL/SDL.h>
#include "background.h"

struct Hero{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface * image;
	int vie;
        int xc , yc;
};
typedef struct Hero Hero;

struct Hero2{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface * image;
	int vie;
        int xc , yc;
};
typedef struct Hero2 Hero2;

int loadHeroImages(Hero * H);

void initHero(Hero *H);

void AnnimateHeroRight(Hero *H);

void AnnimateHeroLeft(Hero *H);

void blitHero(Hero A, SDL_Surface * screen);

void MoveHeroLeft(Hero *H);

void MoveHeroRight(Hero *H);

void freeHero(Hero *H);

int loadHeroImages2(Hero2 * H);

void initHero2(Hero2 *H);



void blitHero2(Hero2 A, SDL_Surface * screen);

void MoveHeroLeft2(Hero2 *H);

void MoveHeroRight2(Hero2 *H);

void freeHero2(Hero2 *H);

#endif

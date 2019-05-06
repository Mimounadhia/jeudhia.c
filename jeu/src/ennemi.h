#ifndef Ennemi_H
#define Ennemi_H
#include <SDL/SDL.h>
#include "background.h"
#include "hero.h"
struct Ennemi2{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
SDL_Rect positionAnimation2;
	SDL_Surface * image;
     
	
};
typedef struct Ennemi2 Ennemi2;
struct Ennemi{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
SDL_Rect positionAnimation2;
	SDL_Surface * image;
        int xc , yc;
	
};
typedef struct Ennemi Ennemi;

int loadEnnemiImages(Ennemi * E);

void initEnnemi(Ennemi *E);
void AnnimateEnnemi2(Ennemi *E );
void AnnimateEnnemi(Ennemi *E);
void MoveEnnemi(Ennemi *E);
void MoveEnnemi2(Ennemi *E);
int collision (Ennemi *E,Hero *H);

int loadEnnemiImages2(Ennemi2 * E);

void initEnnemi2(Ennemi2 *E);
void MoveEnnemi1(Ennemi2 *E);
void MoveEnnemi22(Ennemi2 *E);


void freeEnnemi2(Ennemi2 *E);

#endif

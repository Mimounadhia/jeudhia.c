#include <SDL/SDL.h>
#include "defs.h"
#include "ennemi.h"
#include "background.h"
#include "hero.h"


int loadHeroImages(Hero * A)
{
	A->image = IMG_Load("../images/Hero.png");

	if(A->image == NULL) {
		printf("Unable to load Hero gif:%s\n", SDL_GetError());
		return (-1);
	}


	return (0);
}

int loadHeroImages2(Hero2 * A)
{
	A->image = IMG_Load("../images/m.png");

	if(A->image == NULL) {
		printf("Unable to load Hero gif:%s\n", SDL_GetError());
		return (-1);
	}


	return (0);
}
void initHero2(Hero2* A)
{
	A->positionAbsolue.x = 280;
	A->positionAbsolue.y = 75;
	A->positionAbsolue.w = 280;
	A->positionAbsolue.h = 200;

        
}
void initHero(Hero* A)
{
	A->positionAbsolue.x = 10;
	A->positionAbsolue.y = 300;
	A->positionAbsolue.w = Hero_WIDTH;
	A->positionAbsolue.h = Hero_HEIGHT;
	A->positionAnimation.x = 0;
	A->positionAnimation.y = 0;
	A->positionAnimation.w = Hero_WIDTH;
	A->positionAnimation.h = Hero_HEIGHT;
        A->xc=A->positionAbsolue.x+44.5;
        A->yc=A->positionAbsolue.y-61;	
}
void blitHero(Hero A, SDL_Surface* screen)
{
	SDL_BlitSurface(A.image, &A.positionAnimation, screen, &A.positionAbsolue);
}
void blitHero2(Hero2 A, SDL_Surface* screen)
{
	SDL_BlitSurface(A.image, NULL, screen, &A.positionAbsolue);
}
void AnnimateHeroRight(Hero *A)
{
        A->positionAnimation.x += Hero_WIDTH;
	A->positionAnimation.x = A->positionAnimation.x % (Hero_WIDTH * 9);	
        A->positionAnimation.y = 0;
        
}
void AnnimateHeroLeft(Hero *A)
{
        A->positionAnimation.x += Hero_WIDTH ;	
	A->positionAnimation.x = A->positionAnimation.x % (Hero_WIDTH * 9);
	A->positionAnimation.y = Hero_HEIGHT;
}

void MoveHeroRight(Hero *A)
{
        A->positionAbsolue.x +=20;    
}

void MoveHeroLeft(Hero *A)
{
	A->positionAbsolue.x -=20;
}




void MoveHeroRight2(Hero2 *A)
{
        A->positionAbsolue.x +=6;    
}

void MoveHeroLeft2(Hero2 *A)
{
	A->positionAbsolue.x -=6;
}
void freeHero(Hero *A)
{
	SDL_FreeSurface(A->image);
}
void freeHero2(Hero2 *A)
{
	SDL_FreeSurface(A->image);
}

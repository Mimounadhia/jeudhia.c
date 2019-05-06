#include <SDL/SDL.h>
#include <math.h>
#include "defs.h"
#include "background.h"
#include "ennemi.h"
#include "hero.h"

#include "jeu.h"


int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
int d=0;
	Hero hero;
        Hero2 h;
	Ennemi ennemi;
       Ennemi2 e;
	Background Backg;
        minimap  m;
	SDL_Event event;
	int keysHeld[323] = {0}; 	
	

	if(loadEnnemiImages(&ennemi) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}
	if(loadEnnemiImages2(&e) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}
	if(loadHeroImages(&hero) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}

if(loadHeroImages2(&h) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}
	if(loadBackground(&Backg) == -1) {
		printf("Erreur Chargement Background Images\n");
		return(-1);
	}
		if(loadBackground2(&m) == -1) {
		printf("Erreur Chargement  Images\n");
		return(-1);
	}
	
        init_minimap(&m);
	initBackground(&Backg);
	initEnnemi(&ennemi);
initEnnemi2(&e);
        initHero(&hero);
	initHero2(&h);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {

	

		while (SDL_PollEvent(&event)) {
			
			switch (event.type) {
				
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;				
				break;

			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				
				break;
			}
			
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
		
                        if(keysHeld[SDLK_RIGHT]) {
                  
				{MoveHeroRight(&hero);
				 AnnimateHeroRight(&hero);
                                 MoveHeroRight2(&h);
				 

}

                                

				}

				if((keysHeld[SDLK_LEFT])&&(hero.positionAbsolue.x>=0)) { 
				MoveHeroLeft(&hero);
				AnnimateHeroLeft(&hero);
                                MoveHeroLeft2(&h);
			
				}

		} 



 if ((((ennemi.positionAbsolue.x)-(hero.positionAbsolue.x))<210)&& (((hero.positionAbsolue.x)-(ennemi.positionAbsolue.x))<0))
{
d++;
MoveEnnemi(&ennemi);
MoveEnnemi1(&e);
AnnimateEnnemi(&ennemi);

}
if ((((ennemi.positionAbsolue.x)-(hero.positionAbsolue.x)) >210 )|| (((hero.positionAbsolue.x)-(ennemi.positionAbsolue.x))>0))
{
while ((ennemi.positionAbsolue.x)<500)
{
MoveEnnemi2(&ennemi);
MoveEnnemi22(&e);
AnnimateEnnemi(&ennemi);
}}


         
		AnnimateEnnemi(&ennemi);
                blitBackground(&Backg,screen);
                 blitmini(&m,screen);
blitEnnemi2(e,screen);
               blitHero2(h,screen);
                blitHero(hero,screen);
		blitEnnemi(ennemi,screen);
             
		SDL_Flip(screen);

	}
   
	freeHero(&hero);
freeHero2(&h);
	freeEnnemi(&ennemi);
freeEnnemi2(&e);
	freeBackground(&Backg);
	free_minimap(&m);
return(0);
}

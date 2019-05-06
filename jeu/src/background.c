#include "background.h"

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = IMG_Load("../images/image.png");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load: %s\n", SDL_GetError());
		return (-1);
	}
	
	
	return (0);
}

int loadBackground2(minimap *m)
{
	// load background
	m->miniImg = IMG_Load("../images/min.png");
	if (m->miniImg == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return (-1);
	}
	
	
	return (0);
}
void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}

void init_minimap(minimap *m)
{

	m->miniPos.x=260;
	m->miniPos.y=0;
	m->miniPos.w=SCREEN_W;
	m->miniPos.h=SCREEN_H;

	

	
}
void blitBackground(Background*Backg,SDL_Surface *screen)
{
	
	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 

}
void blitmini(minimap *m,SDL_Surface *screen)
{
	
	SDL_BlitSurface(m->miniImg, NULL, screen,&(m->miniPos)); 

}
void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}






void free_minimap(minimap *m)
{
	SDL_FreeSurface(m->miniImg);
	
}

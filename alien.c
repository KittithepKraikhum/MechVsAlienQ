//alien.c

#include "alien.h"


//function definition
void InitAlien(Alien * a)
{
	a->health = 100;	//Starting HP
	a->state = ALIEN_IDLE;	//Starting in idle state
	a->pos = (Vector2){600,300};	//Position on screen
}

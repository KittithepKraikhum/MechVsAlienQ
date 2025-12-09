//player.c

#include "player.h"

//function definition
void InitPlayer(Player * p)
{
	p->health = 100;		 //starting HP
	p->state = STATE_IDLE;		//Start in idle state
	p->pos = (Vector2){100,300};	//Position

}

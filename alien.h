//alien.h

#ifndef ALIEN_H
#define ALIEN_H

#include <raylib.h>
#include "player.h"

//FSM States
typedef enum {
	ALIEN_IDLE, //possible player action mode
	ALIEN_ATTACK,
	ALIEN_SHIELD,
	ALIEN_MAGIC
} AlienState;

typedef struct {
	int health;
	AlienState state;
	Vector2 pos;

} Alien;

void InitAlien(Alien * a);

#endif

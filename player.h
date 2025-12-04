//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h> //I need raylib features in this file

//FSM States
typedef enum {
	STATE_IDLE, //possible player action mode
	STATE_ATTACK,
	STATE_SHIELD,
	STATE_MAGIC
} State;

//similar to class struct
typedef struct {
	int health;
	State state;
	Vector2 pos;
} Player;

void InitPlayer(Player * p);

#endif

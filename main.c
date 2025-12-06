//main.c

#include <raylib.h>
#include "player.h"
#include "alien.h"

//creates two possible turn
typedef enum { 
	TURN_PLAYER,
	TURN_ALIEN
} Turn;


int main(void)
{
	//create window
	InitWindow(800,600,"Mech vs Alien");
	
	//Declare player and alien
	Player player;
	Alien alien;

	//current turn the game starts with player's turn
	Turn currentTurn = TURN_PLAYER;

	//Initialize Player and Alien
	InitPlayer(&player);
	InitAlien(&alien);

	//Game loop
	while (!WindowShouldClose())
	{
	//drawing code
	BeginDrawing();
	ClearBackground(RAYWHITE); //color the entire screen to white

	//DRAW HERE
	DrawText("Player HP:",20,20,20, BLACK);	
	DrawText("Alien HP ",20,60,20, BLACK);

	EndDrawing();

	}


CloseWindow();
return 0;
}//end main

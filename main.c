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

		if (currentTurn == TURN_PLAYER)
		{

			//S for attack
			if (IsKeyPressed(KEY_S))
			{
				alien.health -= 10;			//damage to alien
				currentTurn = TURN_ALIEN;  //switch to alien turn
			}

			//will do the shield later

			 else if (IsKeyPressed(KEY_M))
			{
				alien.health -= 25; //more damage than normal attack
				player.health -= 10; //player also get some damage

				currentTurn = TURN_ALIEN;
			}
		}

		else if (currentTurn == TURN_ALIEN)
		{
			player.health -= 10; //damge to player

			currentTurn = TURN_PLAYER;
		}



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

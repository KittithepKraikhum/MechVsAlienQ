//main.c

#include <raylib.h>
#include "player.h"
#include "alien.h"

//creates two possible turn
typedef enum { 
	TURN_PLAYER,
	TURN_ALIEN
} Turn;


bool alienAttack = false;
bool playerShield = false;

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
		//check for game over screen
		if (player.health <= 0)
		{
			currentTurn = -1; // game over state
		}

		if (alien.health <= 0)
		{
			currentTurn = -1;
		}

		if (currentTurn != -1)
		{
			if (currentTurn == TURN_PLAYER)
			{

				//S for attack
				if (IsKeyPressed(KEY_S))
				{
					alien.health -= 10;			//damage to alien
					player.pos.x += 20;			//move
					currentTurn = TURN_ALIEN;  //switch to alien turn
					alienAttack = true; //switch turn
					continue;

				}

				//will do the shield later
				else if (IsKeyPressed(KEY_D))
				{
					playerShield = true;     // activate shield
					currentTurn = TURN_ALIEN;
					alienAttack = true;
					// No damage dealt, just shielding
					continue;
				}

				else if (IsKeyPressed(KEY_M))
				{
					alien.health -= 25; //more damage than normal attack
					player.pos.x += 20;	//move
					player.health -= 10; //player also get some damage
					alienAttack = true;
					currentTurn = TURN_ALIEN;
					continue;
				}
			}

			else if (currentTurn == TURN_ALIEN)  //***** Here
			{
				if (alienAttack == true)
				{
					if (IsKeyPressed(KEY_F))
					{
						if (playerShield == true)
						{
							player.health -= 2; // shield reduces damage a lot 
							playerShield = false; // shield used up
						}
						else
						{
							player.health -= 10; // normal damage
						}
						alien.pos.x -= 20;	//move
						alienAttack = false;
						currentTurn = TURN_PLAYER;
					}
				}
			}

		}

	//drawing code
	BeginDrawing();
	ClearBackground(RAYWHITE); //color the entire screen to white


	//DRAW HERE

	if (currentTurn == -1) //game over
	{
		if (player.health <= 0)
		{
			DrawText("ALIEN WINS!", 100,100,40,RED); //text,x,y,fontSize, color
		}

		else
		{
			DrawText("PLAYER WINS!", 100, 100, 40, RED); //text,x,y,fontSize, color
		}
	}

	//Display whose turn on the screen
	if (currentTurn == TURN_PLAYER)
	{
		DrawText("PLAYER TURN", 200,200,40,BLACK);
	}

	else if (currentTurn == TURN_ALIEN)
	{
		DrawText("ALIEN TURN", 200,200,40,BLACK);
	}

	//Hp lebel
	if (currentTurn != -1) //show player hp when not on gameover screen
	{
		DrawText("Player HP:", 20, 20, 20, BLACK);
		DrawText("Alien HP: ", 20, 60, 20, BLACK);

		DrawText(TextFormat("%d", player.health), 140, 20, 20, BLACK);
		DrawText(TextFormat("%d", alien.health), 140,60,20, BLACK);
		//raylib can't draw number. only string
		//so we need to  use TextFormat to converts the number into text


		//Draw sprite
		DrawRectangle((int)player.pos.x, (int)player.pos.y,80,80, BLUE);

		DrawRectangle((int)alien.pos.x, (int)alien.pos.y, 80, 80, RED);

	}


	EndDrawing();


	}//end while


CloseWindow();
return 0;
}//end main

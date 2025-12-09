run: game.exe 
	./game.exe

game.exe: main.c player.c alien.c 
	gcc main.c player.c alien.c -o game.exe -lraylib -lopengl32 -lgdi32 -lwinmm

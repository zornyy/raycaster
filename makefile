raycaster: main.o display.o gameMap.o player.o vector.o ray.o
	gcc main.o display.o gameMap.o player.o vector.o ray.o -o raycaster -lSDL2 -lm

main.o: main.c
	gcc -c main.c -lm

display.o: main.c src/display.c src/display.h
	gcc -c src/display.c -lSDL2 -lm

gameMap.o: main.c src/gameMap.c src/gameMap.h
	gcc -c src/gameMap.c -lSDL2 -lm

player.o: main.c src/player.c src/player.h 
	gcc -c src/player.c -lSDL2 -lm 

vector.o: main.c src/vector.c src/vector.h
	gcc -c src/vector.c -lSDL2 -lm

ray.o: main.c src/ray.c src/ray.h
	gcc -c src/ray.c -lSDL2 -lm

clean:
	rm *.o raycaster 

raycaster: main.o display.o map.o player.o vector.o
	gcc main.o display.o map.o player.o vector.o -o raycaster -lSDL2 -lm

main.o: main.c
	gcc -c main.c -lm

display.o: main.c src/display.c src/display.h
	gcc -c src/display.c -lSDL2 -lm

map.o: main.c src/map.c src/map.h
	gcc -c src/map.c -lSDL2 -lm

player.o: main.c src/player.c src/player.h 
	gcc -c src/player.c -lSDL2 -lm 

vector.o: main.c src/vector.c src/vector.h
	gcc -c src/vector.c -lSDL2 -lm

clean:
	rm *.o raycaster 

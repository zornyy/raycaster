raycaster: main.o display.o map.o
	gcc main.o display.o map.o -o raycaster -lSDL2

main.o: main.c
	gcc -c main.c

display.o: main.o src/display.c src/display.h
	gcc -c src/display.c -lSDL2

map.o: main.o src/map.c src/map.h
	gcc -c src/map.c -lSDL2

clean:
	rm *.o raycaster 

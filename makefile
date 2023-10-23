raycaster: main.o display.o
	gcc main.o display.o -o raycaster -lSDL2

main.o: main.c
	gcc -c main.c

display.o: main.o src/display.c src/display.h
	gcc -c src/display.c -lSDL2

clean:
	rm *.o raycaster 

all: main

main: default.o main.c 
	gcc main.c -o main default.o -lm
default.o: default.c
	gcc -c default.c -lm
clean:
	rm -f *.o

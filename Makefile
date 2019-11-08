all: main

main: default.o main.c 
	gcc main.c -o main default.o
default.o: default.c
	gcc -c default.c
clean:
	rm -f *.o

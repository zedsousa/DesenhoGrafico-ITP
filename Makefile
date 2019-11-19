all: main

main: default.o extras.o main.c 
	gcc main.c -o main default.o extras.o -lm
default.o: default.c
	gcc -c default.c -lm
extras.o: extras.c 
	gcc -c extras.c -lm
clean:
	rm -f *.o

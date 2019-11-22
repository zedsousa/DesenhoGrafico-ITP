all: main

main: funcoes_basicas.o funcoes_extras.o main.c 
	gcc main.c -o main funcoes_basicas.o funcoes_extras.o -lm
funcoes_basicas.o: funcoes_basicas.c
	gcc -c funcoes_basicas.c -lm
extras.o: funcoes_extras.c 
	gcc -c funcoes_extras.c -lm
clean:
	rm -f *.o

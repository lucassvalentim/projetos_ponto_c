all: main.o velha.o
	gcc main.o velha.o -o jogo

main.o: main.c velha.h
	gcc -c main.c

velha.o: velha.c velha.h
	gcc -c velha.c

run: jogo
	./jogo
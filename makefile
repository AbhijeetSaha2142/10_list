all: main.o pokemon.o
	gcc -o main main.o pokemon.o
main.o: main.c pokemon.h
	gcc -c main.c
pokemon.o: pokemon.c pokemon.h
	gcc -c pokemon.c
run:
	./main
clean:
	rm *.o

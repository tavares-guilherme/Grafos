all: lista.o grafo.o main.o
		gcc lista.o grafo.o main.o -o programa

lista.o: lista.c
		gcc lista.c -c

grafo.o: grafo.c
		gcc grafo.c -c

main.o: main.c
		gcc main.c -c

run: 
		./programa

clean:
		rm -rf programa *.o
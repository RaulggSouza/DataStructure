CC = gcc
CFLAGS = -Wall -Wextra

all: meu_programa

meu_programa: list.o funcoes.o
	$(CC) $(CFLAGS) -o meu_programa list.o funcoes.o

list.o: list.c funcoes.h
	$(CC) $(CFLAGS) -c -o list.o list.c

funcoes.o: funcoes.c funcoes.h
	$(CC) $(CFLAGS) -c -o funcoes.o funcoes.c

clean:
	rm -f meu_programa list.o funcoes.o
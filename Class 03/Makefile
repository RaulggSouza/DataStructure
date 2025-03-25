CC = gcc
CFLAGS = -Wall -Wextra

all: meu_programa

meu_programa: main.o ordered_list.o
	$(CC) $(CFLAGS) -o meu_programa main.o ordered_list.o

main.o: main.c ordered_list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

ordered_list.o: ordered_list.c ordered_list.h
	$(CC) $(CFLAGS) -c -o ordered_list.o ordered_list.c

clean:
	rm -f meu_programa main.o ordered_list.o

run:
	./meu_programa.exe

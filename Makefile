# compiler
CC=gcc
# flagy
CFLAGS= -fsanitize=address -g -Werror=vla -lm

projekt: main.o drawing.o
	$(CC) $(CFLAGS) main.o drawing.o -o projekt

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

drawing.o : drawing.c
	$(CC) $(CFLAGS) -c drawing.c

clean:
	rm *.o
	rm drawing

all: clean drawing
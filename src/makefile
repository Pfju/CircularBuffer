# compiler configuration
CC = gcc
# compiler flags
CFLAGS = -Wall -Wextra
# objects which shall be linked
objects = main.o CircularBuffer.o

all : $(objects)
	$(CC) $(CFLAGS) -o main $(objects)

main.o : main.c CircularBuffer.h
	$(CC) $(CFLAGS) -c main.c

CircularBuffer.o : CircularBuffer.c CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.c

clean : 
	rm main $(objects)

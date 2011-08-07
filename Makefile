#
# Makefile to testing Assignment 1
#
CC=g++
CFLAGS=-g -Wall

all: main

main: main.o Board.o
	$(CC) $(CFLAGS) -o main main.o Board.o

main.o: Board.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Board.o: Board.h Board.cpp
	$(CC) $(CFLAGS) -c Board.cpp

clean:
	rm *.o main


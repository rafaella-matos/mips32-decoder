
CC=gcc
CXX=g++

TARGET=main

all:
	$(CC) main.c -o $(TARGET)

clean: 
	rm *.exe
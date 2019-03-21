CC=g++
CFLAGS= -std=c++11 -Wall -O -g
LDFLAGS=
EXEC=main


all: mkdir $(EXEC)

main: main.o pugixml.o
				$(CC) -o bin/main obj/pugixml.o obj/main.o $(LDFLAGS)

%.o: sources/%.cpp
				$(CC) -o obj/$@ -c $< $(CFLAGS)

mkdir:
	[ -d bin ] || mkdir -p bin; [ -d obj ] || mkdir -p obj

clean:
				rm -f obj/*.o core

clear: clean
			  rm -f bin/*

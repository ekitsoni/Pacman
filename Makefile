all:	
	g++ -c Engine.h Engine.cpp
	g++ -c Moving.h Moving.cpp
	g++ -c Gnome.h Gnome.cpp
	g++ -c Potter.h Potter.cpp
	g++ -c Traal.h Traal.cpp
	g++ -c HiScore.h HiScore.cpp
	g++ -c main.cpp
	g++ -o main Engine.o Moving.o Potter.o Gnome.o Traal.o HiScore.o main.o -lncurses
	./main map1.txt

clean:
	rm -f main Engine.o Moving.o Potter.o Gnome.o Traal.o main.o

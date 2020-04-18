game: game.cpp game.o
	g++ -c game.cpp
	g++ game.o -o game -lsfml-graphics -lsfml-window -lsfml-system


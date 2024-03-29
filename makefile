FLAGS = -pedantic-errors -std=c++11 

instruction.o: instruction.cpp instruction.h
	g++ $(FLAGS) -c instruction.cpp
map.o: map.cpp map.h
	g++ $(FLAGS) -c map.cpp
printmap.o: printmap.cpp printmap.h
	g++ $(FLAGS) -c printmap.cpp
map_main.o: map_main.cpp instruction.h map.h printmap.h
	g++ $(FLAGS) -c map_main.cpp
map_main: map_main.o instruction.o map.o printmap.o
	g++ $(FLAGS) instruction.o map.o printmap.o map_main.o -o map_main



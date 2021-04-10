FLAGS = -pedantic-errors -std=c++11 

instruction.o: instruction.cpp instruction.h
	g++ $(FLAGS) -c instruction.cpp
map.o: map.cpp map.h
	g++ $(FLAGS) -c map.cpp
printmap.o: printmap.cpp printmap.h
	g++ $(FLAGS) -c print.cpp
map_main.o: map_main.cpp instruction.h map.h printmap.h
	g++ $(FLAGS) instruction.o map.o printmap.o map_main.o -o map_main
clean:
	rm -f map_main *.o
.PHONY:clean

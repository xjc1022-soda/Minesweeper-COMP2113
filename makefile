instruction.o: instruction.cpp instruction.h
	g++ -c instruction.cpp
map.o: map.cpp map.h
	g++ -c map.cpp
printmap.o: print.cpp print.h
	g++ -c print.cpp
map_main.o: map_main.cpp instruction.h map.h printmap.h
	g++ instruction.o map.o printmap.o map_main.o -o map_main
clean:
	rm -f map_main *.o
.PHONY:clean

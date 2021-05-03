OBJECTS = main.o problem.o element.o greedy.o solution.o GRASP.o localSearch.o interChange.o algorithm.o
CFLAGS = -c -O3 -std=c++17 -I../include
SRC = src/main.cc src/problem.cc src/element.cc src/greedy.cc src/solution.cc src/GRASP.cc src/localSearch.cc src/interChange.cc src/algorithm.cc

exe: $(OBJECTS)
	g++ $(SRC) -o exe
	mv *.o ./obj
	
main.o:
	g++ $(CFLAGS) ./src/main.cc

problem.o:
	g++ $(CFLAGS) ./src/problem.cc

element.o:
	g++ $(CFLAGS) ./src/element.cc

greedy.o:
	g++ $(CFLAGS) ./src/greedy.cc

solution.o:
	g++ $(CFLAGS) ./src/solution.cc

GRASP.o:
	g++ $(CFLAGS) ./src/GRASP.cc

localSearch.o:
	g++ $(CFLAGS) ./src/localSearch.cc

interChange.o:
	g++ $(CFLAGS) ./src/interChange.cc

algorithm.o:
	g++ $(CFLAGS) ./src/interChange.cc


.PHONY: 

default:
	make exe

clean:
	rm -rf ./obj/*.o

run:
	./exe input/max_div_15_2.txt
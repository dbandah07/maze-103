CXX = g++ -g -Wall -Werror

all: queue.o maze-test queue-test

clean:
	rm -f *.o queue-test maze-test

queue.o: queue.cpp queue.h location.h
	$(CXX) -c $< -o $@

maze.o: maze.cpp maze.h queue.h location.h
	$(CXX) -c $< -o $@

queue-test: queue.o queue-test.cpp
	$(CXX) queue.o queue-test.cpp -o queue-test

maze-test: maze.cpp queue.o maze.o
	$(CXX) $@.cpp queue.o maze.o -o $@

# # bug: being treated as a terminal rule?
# %: %.cpp queue.o mazeio.o
# 	$(CXX) $@.cpp queue.o mazeio.o -o $@

tar:
	tar cvf amaze.tar maze?.in *.cpp *.h readme.txt Makefile


CC = g++

DEPS = starter.h

all: starter.o main.o
	$(CC) -std=c++11 starter.o main.o -o bowling

starter.o: starter.cpp $(DEPS)
	$(CC) -c -std=c++11 starter.cpp

main.o: main.cpp $(DEPS)
	$(CC) -c -std=c++11 main.cpp

clean:
	rm -f *.o bowling
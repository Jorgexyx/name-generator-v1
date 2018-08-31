CFLAGS=-std=c++11 -ggdb

OBJECTS=main.o person.o

nameGenerator.x: $(OBJECTS)
	g++ $(CLAGS) $(OBJECTS) -o nameGenerator.x

person.o: person.hpp person.cpp
	g++ $(CFLAGS) -c person.cpp -o person.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o
clean:
	rm -fr *~ $(OBJECTS) artist.x

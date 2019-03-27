all: program2

program2: program2.o
	g++ program2.o -o program2

program2.o: program2.cpp
	g++ -g -c program2.cpp

clean:
	rm -f *.o


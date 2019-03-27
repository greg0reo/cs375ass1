all: program1 program2 program3


program1: program1.o
	g++ program1.o -o program1

program1.o: program1.cpp
	g++ -g -c program1.cpp



program2: program2.o
	g++ program2.o -o program2

program2.o: program2.cpp
	g++ -g -c program2.cpp



program3: program3.o
	g++ program3.o -o program3

program3.o: program3.cpp
	g++ -g -c program3.cpp



clean:
	rm -f *.o


all: test_signal

test_signal: main.o object.o db_object.o
	g++  -o test_signal main.o object.o db_object.o

main.o: main.cpp
	g++ -c main.cpp

object.o: object.cpp
	g++ -c object.cpp

db_object.o: db_object.cpp
	g++ -c db_object.cpp

install: all


clean:
	-rm *.o
	-rm test_signal

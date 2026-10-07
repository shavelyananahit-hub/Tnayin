calculator: main.o calculator.o
	g++ main.o calculator.o -o calculator

main.o: main.cpp calculator.h
	g++ -c main.cpp

calculator.o: calculator.cpp calculator.h
	g++ -c calculator.cpp

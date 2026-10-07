factorial: main.o get_number.o check_number.o calculate_factorial.o print_result.o
	g++ main.o get_number.o check_number.o calculate_factorial.o print_result.o -o factorial

main.o: main.cpp get_number.h check_number.h calculate_factorial.h print_result.h
	g++ -c main.cpp

get_number.o: get_number.cpp get_number.h
	g++ -c get_number.cpp

check_number.o: check_number.cpp check_number.h
	g++ -c check_number.cpp

calculate_factorial.o: calculate_factorial.cpp calculate_factorial.h
	g++ -c calculate_factorial.cpp

print_result.o: print_result.cpp print_result.h
	g++ -c print_result.cpp

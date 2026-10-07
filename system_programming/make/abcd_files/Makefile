abcd: ab.o ac.o ad.o myprog.o
	g++ ab.o ac.o ad.o myprog.o -o abcd

ab.o: ab.cpp ab.h gv.h
	g++ -c ab.cpp

ac.o: ac.cpp ac.h gv.h
	g++ -c ac.cpp

ad.o: ad.cpp ad.h gv.h
	g++ -c ad.cpp

myprog.o: myprog.cpp ab.h ac.h ad.h gv.h
	g++ -c myprog.cpp

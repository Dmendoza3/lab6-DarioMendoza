main:	funciones.o main.o
	g++ funciones.o main.o -o main

main.o: funciones.o
	g++ -c main.cpp

funciones.o:	funciones.h funciones.cpp
	g++ funciones.cpp -c

clean:
	rm *.o lab6

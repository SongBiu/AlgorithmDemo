run: main.o sort.o
	g++ -o run main.o sort.o
sort.o: sort.cpp sort.h
	g++ -c sort.cpp -o sort.o
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++11
clean:
	rm *.o run
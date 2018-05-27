run: main.o sort.o
	clang++ main.o sort.o -o run
sort.o: sort.cpp sort.h
	clang++ -c sort.cpp -o sort.o
main.o: main.cpp
	clang++ -c main.cpp -o main.o -std=c++11
clean:
	rm *.o run data build
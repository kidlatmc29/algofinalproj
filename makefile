main : main.o
	g++ -o main

main.o: main.cpp
	g++ -c -pedantic -Wall -Werror main.cpp

clean:
	rm *.o
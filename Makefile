test.exe : main.o 
	gcc main.o -std=c++11 -lstdc++ -o test.exe

main.o : main.cpp
	gcc -c main.cpp -std=c++11 -lstdc++ -o main.o

clean:
	rm -f main.o test.exe
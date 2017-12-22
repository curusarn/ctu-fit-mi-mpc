
files=main.cc string.h 
cxx_flags=-std=c++14 -pedantic -Wall -Wextra -o main.out -g

valgrind: compile
	valgrind ./main.out

run: compile
	./main.out

compile:
	g++ ${cxx_flags} -O2 ${files} 


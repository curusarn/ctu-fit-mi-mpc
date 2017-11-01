
files=main.cc sso.cc

valgrind: compile
	valgrind ./main_O2.out

run: compile
	./main_O2.out

compile:
	g++ -std=c++11 -g -pedantic -Wall -Wextra -O2 -o main_O2.out ${files} 


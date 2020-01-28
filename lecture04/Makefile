compile:
	clang++ test.cpp -std=c++11 -ggdb3 -pedantic -Weverything -Wno-weak-vtables -Wno-c++98-compat

valgr:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./a.out
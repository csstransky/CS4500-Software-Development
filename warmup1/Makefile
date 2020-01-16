comp:
	clang++ -std=c++11 -Wall -g main.cpp

run:
	./a.out

clean:
	rm -rf a.out* *~

test:
	./a.out
	./a.out test
	./a.out "Test String"
	./a.out -i 12
	./a.out test.txt
	./a.out -f test.txt lego man -i 5 with a hat
	./a.out -f
	./a.out -i
	./a.out -f lol.txt
	./a.out -i -1
	./a.out -i 0
	./a.out -i 65535
	./a.out -i 65536
	./a.out -i 10 -i 14
	./a.out -f main.cpp
	./a.out -f Makefile
	./a.out -f test.txt -f nevermind.txt
	./a.out -f file
	./a.out -i 122222 -f face  comment
	./a.out comment
	./a.out asd asd asd -i 827 -82 -i 2 -f 2e3lkd.txt -d2 -f 244 -i


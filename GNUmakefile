all:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic -std=c++11 cache_memory.cpp -o start
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./start
begin:
	./start
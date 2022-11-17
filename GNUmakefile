all:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic -std=c++11 LFU_cache.cpp LRU_cache.cpp cache_memory.cpp  -o start
LRU:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic -std=c++11 LFU_cache.cpp LRU_cache.cpp cache_memory.cpp -LRU -o start
LFU:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic -std=c++11 LFU_cache.cpp LRU_cache.cpp cache_memory.cpp -LFU -o start

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./start
begin:
	./start
debug:
	gdb ./start
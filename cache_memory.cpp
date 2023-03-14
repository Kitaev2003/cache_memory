#include "cache_memory.h"

int main(int argc, char *argv[])
{
    size_t quantity = 0, max_size = 0;

    std::cout << "Input max size cache and quantity elements:" <<  std::endl;
    std::cin >> max_size >> quantity;

    LRU_MEMORY LRU (max_size);
    int element = 0;

    while (quantity != 0)
    {
        std::cin >> element;
        LRU.LRU_Push_Cache(element);
        quantity--;
    }

    std::cout << LRU.hits_in_cache << std::endl;

    return RUN_ALL_TESTS();
}



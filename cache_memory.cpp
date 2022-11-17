#include "cache_memory.h"


int main(int argc, char *argv[])
{
    size_t quantity = 0, max_size = 0;

    std::cout << "Input max size cache and quantity elements:" <<  std::endl;
    std::cin >> max_size >> quantity;

    LFU_MEMORY LFU (max_size);
    int element = 0;

    while (quantity != 0)
    {
        std::cin >> element;
        LFU.LFU_Push_Cache(element);

        quantity--;
    }
    LFU.LFU_Print();
    return 0;
}


#ifdef LRU
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

    LFU.Print_Hash_Table();
    return 0;
}
#endif



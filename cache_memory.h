#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>


typedef std::list <int> List;
typedef std::unordered_map<int, List> Hash_Table;

class Cache_Memory
{
    private:
    List* line;

    Hash_Table cache;

    int size_cache = 0;
    int max_size_cache = 0;
    int max_lvl = 0;
    int hits_in_cache = 0; 
    
    public:
    Cache_Memory(int max_size);
    ~Cache_Memory();

    void LFU_Cache (const int element);
    bool LFU_Search_Element (const int element);
    void LFU_Push_Cache (const int element);
    void Print_Hash_Table();
};

Cache_Memory::Cache_Memory(int max_size)
{
    max_size_cache = max_size;
    max_lvl = 10;

    line = new List[10]; 
    Hash_Table::key_type key = max_lvl - 1; 

    for(int i = 0; i < max_lvl ; i++)
    {  
        cache[key] = line[i];
        key--;
    }
}
Cache_Memory::~Cache_Memory()
{
    int i = 0;

    while(i < 10)
    {
        line[i].clear();
        i++;
    }

    cache.clear();

    delete [] line;
}
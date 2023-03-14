#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
#include <gtest/gtest.h>

typedef std::list <int> List;
typedef std::unordered_map<int, List> LFU_Hash_Table;
typedef std::unordered_map<int, List::iterator> LRU_Hash_Table;

class LFU_MEMORY final
{
    private:
    List* line_;
    LFU_Hash_Table cache_;

    int size_cache = 0;
    int max_size_cache = 0;
    int max_lvl = 0;
    
    public:
    int hits_in_cache = 0; 
    
    LFU_MEMORY(int max_size);
    ~LFU_MEMORY();
    
    bool LFU_Search_Element (const int element);
    void LFU_Push_Cache (const int element);
    void LFU_Print();
};

class LRU_MEMORY final
{
    private:
    List line_;
    LRU_Hash_Table cache_;

    int max_size_cache = 0;

    public:
    int hits_in_cache = 0; 

    LRU_MEMORY(int max_size);
    ~LRU_MEMORY();

    void LRU_Push_Cache (const int element);
    bool LRU_Search_Element (const int element);
    void LRU_Print ( );
};


#include "cache_memory.h"

void Cache_Memory::LFU_Cache(const int element)
{
    if (LFU_Search_Element(element))
    {
        LFU_Push_Cache(element);
    }
}

bool Cache_Memory::LFU_Search_Element(const int element)
{    
    List::iterator List_Iter;
    Hash_Table::iterator Hash_Iter;

    for(Hash_Iter = cache.begin(); Hash_Iter != cache.end(); Hash_Iter++)
    {
        if (Hash_Iter->second.empty() == false)
        {
            for (List_Iter = Hash_Iter->second.begin(); List_Iter != Hash_Iter->second.end(); List_Iter++)
            {
                if (*List_Iter == element)
                {
                    Hash_Table::iterator Hash_Iter1 = Hash_Iter ;

                    hits_in_cache++;
                    Hash_Iter1++;
                    
                    if(Hash_Iter1 != cache.end())
                    {
                        Hash_Iter->second.erase(List_Iter);
                        Hash_Iter1->second.push_front(element);
                    }
                    return false;
                }
            }                
        }
    }
    return true;
}

void Cache_Memory::LFU_Push_Cache(const int element)
{
    Hash_Table::iterator Hash_Iter = cache.begin();

    if (size_cache < max_size_cache)
    {
        Hash_Iter->second.push_front(element);
        size_cache++;
    }
    else
    {
        for (Hash_Iter = cache.begin(); Hash_Iter->second.empty(); Hash_Iter++){}

        Hash_Iter->second.pop_back();
        cache.begin()->second.push_back(element);
    }
}

void Cache_Memory::Print_Hash_Table()
{   
    std::cout << "-----Print cache-----" << std::endl;
    for(Hash_Table::iterator it = cache.begin(); it!= cache.end(); it++)
    {   
        if (it->second.empty() == false)
        {
            std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<int>(std::cout << "key = " << it->first << ": " , "|" ));
            std::cout << std::endl;
        }
    }
}   
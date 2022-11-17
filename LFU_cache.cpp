#include "cache_memory.h"

LFU_MEMORY::LFU_MEMORY(int max_size){
    max_size_cache = max_size;
    max_lvl = 10;

    line_ = new List[10]; 
    LFU_Hash_Table::key_type key = max_lvl - 1; 

    for(int i = 0; i < max_lvl ; ++i){  
        cache_[key] = line_[i];
        key--;
    }
}

LFU_MEMORY::~LFU_MEMORY(){
    int i = 0;

    while(i < 10){
        line_[i].clear();
        i++;
    }
    cache_.clear();

    delete [] line_;
}

bool LFU_MEMORY::LFU_Search_Element(const int element){    
    List::iterator List_Iter;
    LFU_Hash_Table::iterator Hash_Iter;

    for(Hash_Iter = cache_.begin(); Hash_Iter != cache_.end(); ++Hash_Iter){

        if (Hash_Iter->second.empty() == false){
            for (List_Iter = Hash_Iter->second.begin(); List_Iter != Hash_Iter->second.end(); ++List_Iter){

                if (*List_Iter == element){
                    LFU_Hash_Table::iterator Hash_Iter1 = Hash_Iter ;

                    hits_in_cache++;
                    Hash_Iter1++;
                    
                    if(Hash_Iter1 != cache_.end()){
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

void LFU_MEMORY::LFU_Push_Cache(const int element)
{
    if(LFU_Search_Element(element)){
        LFU_Hash_Table::iterator Hash_Iter = cache_.begin();

        if (size_cache < max_size_cache){
            Hash_Iter->second.push_front(element);
            size_cache++;
        }
        else{
        for (Hash_Iter = cache_.begin(); Hash_Iter->second.empty(); Hash_Iter++){}
            Hash_Iter->second.pop_back();
            cache_.begin()->second.push_back(element);
        }
    }
}

void LFU_MEMORY::LFU_Print()
{   
    std::cout << "-----Print cache-----" << std::endl;
    for(LFU_Hash_Table::iterator it = cache_.begin(); it!= cache_.end(); ++it)
    {   
        if (it->second.empty() == false)
        {
            std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<int>(std::cout << "key = " << it->first << ": " , "|" ));
            std::cout << std::endl;
        }
    }
}   
#include "cache_memory.h"

LRU_MEMORY::LRU_MEMORY(int max_size){
    max_size_cache = max_size;
}

LRU_MEMORY::~LRU_MEMORY(){
    line_.clear();
    cache_.clear(); 
}

void LRU_MEMORY::LRU_Push_Cache (const int element){
    List::iterator List_Iter;
    LRU_Hash_Table::iterator Hash_Iter; 

    if ((Hash_Iter = cache_.find(element)) == cache_.end()){
        if(line_.size() == max_size_cache){
            cache_.erase(line_.back());
            line_.erase(--line_.end());
        }
        line_.push_front(element);
        cache_[element] = line_.begin(); 
    }
    else{
        line_.erase(Hash_Iter->second);
        line_.push_front(element);
        hits_in_cache++;
    }
}

bool LRU_MEMORY::LRU_Search_Element(const int element){
    if (cache_.find(element) != cache_.end()){
        return true;
    }
    else{
        return false;
    }
}

void LRU_MEMORY::LRU_Print(){

    List::iterator List_Iter;
    std::cout << "LRU_cache:|";

    for(List_Iter = line_.begin(); List_Iter != line_.end(); ++List_Iter){
        std::cout <<*List_Iter << "|";
    }
    std::cout<<std::endl;
}
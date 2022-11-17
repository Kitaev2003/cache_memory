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
        if(size_cache == max_size_cache){
            cache_.erase(line_.back());
            line_.pop_back();
        }
        else{
            size_cache++; 
        }
    }
    line_.erase(Hash_Iter->second);
    line_.push_front(element);
    cache_[element] = line_.begin(); 
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

    for(List_Iter = line_.begin(); List_Iter != line_.end(); ++List_Iter){
        std::cout << "LRU_cache:" << *List_Iter << "|";
    }
    std::cout<<std::endl;
}
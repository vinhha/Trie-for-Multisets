#ifndef ____TrieNode__
#define ____TrieNode__

#include <stdio.h>
#include "BasicTrieNode.h"


class TrieNode: public BasicTrieNode{
private:
    BasicTrieNode *ptr[TrieMaxElem];
public:
    TrieNode();
    int WhoAmI() {return(2);}
    bool CheckTrie(int*);
    BasicTrieNode* GetPtr(int i){return ptr[i];}
    void SetPtr(int i, BasicTrieNode* j){ptr[i] = j;}
    //Helper functions...
    bool CheckTrieNodeEmpty();
    int Count();
    int CountAll(); 
};

#endif 

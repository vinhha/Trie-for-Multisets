#include "TrieNode.h"

//Constructor
TrieNode::TrieNode(){
    BasicTrieNode();
    int i;
    for (i = 0; i < TrieMaxElem; i++) {
        SetPtr(i,0);
    }
}

//Method Implementations
bool TrieNode::CheckTrie(int* pcount){
    int i,countl;
    countl= *pcount;
    for(i=0; i<TrieMaxElem; i++)
    {if(GetPtr(i)!=0)
        if(!GetPtr(i)->CheckTrie(pcount)) {return false;}
    }
    if(countl == *pcount) return false;
    if (GetPtr2MS() != 0) (*pcount)++;
    return true;
}

bool TrieNode::CheckTrieNodeEmpty(BasicTrieNode* current){
    if (MSDefined()) {
        return false;
    }
    for (int i = 0; i<TrieMaxElem; i++){
        if (GetPtr(i)) {
            return false;
        }
    }
    return true;
}

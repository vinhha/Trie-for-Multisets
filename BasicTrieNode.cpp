#include "BasicTrieNode.h"

using namespace std;

bool BasicTrieNode::CheckTrie(int* pcount){
    if(ptr2ms == 0) {return false;}
    (*pcount)++;
    return true;
}

void BasicTrieNode::DeleteCurrentMS(){
    if (MSDefined()) {
        if (GetPtr2MS()->GetPtr2PV() != 0) {
            MultiSet* current = GetPtr2MS();
            SetPtr2MS(current->GetPtr2PV());
            current->DeleteSet();
            delete current;
        }
        else{
            MultiSet* current = GetPtr2MS();
            current->DeleteSet();
            delete current;
            SetPtr2MS(0);
        }
    }
    /*
     Function Description: 
     1. If MS is defined for trie node
        a. If there is also a previous MultiSet:
            i. Set MultiSet to previous
            ii. Delete current MultiSet
        b. Otherwise, just delete the current MultiSet and set the Multiset pointer to 0
     */
}

int BasicTrieNode::Count(){
    int result = 0;
    if (GetPtr2MS() != 0) {
        result = 1;
    }
    return result;
}

int BasicTrieNode::CountMS(){
    int result = 0;
    if (!MSDefined()) {
        return 0;
    }
    MultiSet* ms = GetPtr2MS();
    result += 1;
    while (ms->GetPtr2PV() != 0) {
        ms = ms->GetPtr2PV();
        result += 1;
    }
    return result;
}



#include "BasicTrieNode.h"

bool BasicTrieNode::CheckTrie(int* pcount)
{if(ptr2ms == 0) {return false;}
    (*pcount)++;
    return true;
}

void DeleteCurrentMS(){
    if (MSDefined()) {
        if (current->GetPtr2PV() != 0) {
            MultiSet* current = GetPtr2MS();
            SetPtr2MS(current->GetPtr2PV());
            current->DeleteSet();
        }
        else{
            MultiSet* current = GetPtr2MS();
            current->DeleteSet();
            this->SetPtr2MS(0);
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

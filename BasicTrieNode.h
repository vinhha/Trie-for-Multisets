#ifndef ____BasicTrieNode__
#define ____BasicTrieNode__

#include <stdio.h>
#include <iostream>
#include "MultiSet.h"

const int StrMaxElem = 81;
const int TrieMaxElem = 26;

class BasicTrieNode {
    
private:
    MultiSet *ptr2ms;
public:
    BasicTrieNode(){ptr2ms = 0;}
    virtual int WhoAmI() {return(1);}
    virtual bool CheckTrie(int*);
    virtual void SetPtr(int i, BasicTrieNode* j){}
    virtual bool CheckTrieNodeEmpty();
    virtual BasicTrieNode* GetPtr(int i){}
    void SetPtr2MS(MultiSet* ptr){ptr2ms = ptr;}
    MultiSet* GetPtr2MS(){return ptr2ms;}
    
    //Helper functions...
    bool MSDefined(){return (ptr2ms != 0);}
    void DeleteCurrentMS();
    virtual int Count();
    int CountMS();
    virtual int CountAll(){}
    virtual int CountGT(int x){}
    virtual bool CheckPtrs(){}

};

#endif 

#include "TrieNode.h"
#include <iostream> 

using namespace std; 


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
    for(i=0; i<TrieMaxElem; i++){
        if(GetPtr(i)!=0){
            if(!GetPtr(i)->CheckTrie(pcount)){
                return false;
            }
        }
    }
    if(countl == *pcount) {return false;}
    if (GetPtr2MS() != 0) (*pcount)++;
    return true;
}

bool TrieNode::CheckTrieNodeEmpty(){
    if (MSDefined()) {
        return false;
    }
    for (int i = 0; i<TrieMaxElem; i++){
        if (GetPtr(i) != 0) {
            return false;
        }
    }
    return true;
}

bool TrieNode::CheckPtrs(){
    for (int i = 0; i<TrieMaxElem; i++){
        if (GetPtr(i) != 0) {
            return false;
        }
    }
    return true;
}

int TrieNode::Count(){
  int result = 0;
  if (GetPtr2MS() != 0) {
    result += 1;
  }
  for (int i = 0; i < TrieMaxElem; i++){
    if (GetPtr(i))
      result += GetPtr(i)->Count();
  }
  return result;
}

int TrieNode::CountAll(){
    int result = 0;
    if (GetPtr2MS() != 0) {
        result += CountMS();
    }
    for (int i = 0; i < TrieMaxElem; i++){
        if (GetPtr(i) != 0){
            if(GetPtr(i)->WhoAmI() == 1)
                result += GetPtr(i)->CountMS();
            else
                result += GetPtr(i)->CountAll();
        }
    }
    return result;
}

int TrieNode::CountGT(int x){
    int result = 0;
    if (GetPtr2MS() != 0) {
        result += CountMS();
    }
    for (int i = 0; i < TrieMaxElem; i++){
        if (GetPtr(i) != 0){
            if(GetPtr(i)->WhoAmI() == 1)
                result += GetPtr(i)->CountMS();
            else
                result += GetPtr(i)->CountAll();
        }
    }
    return result;
}





#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <stdio.h>
#include <string> 
#include "BasicTrieNode.h"
#include "TrieNode.h"
#include "SLL.h"
#include "WBLT.h"
#include "SLLNode.h"
#include "WBLTNode.h"

class Trie {
private:
    BasicTrieNode *root;
    bool Delete(char s[], int i, BasicTrieNode *current);
    void DeleteAllMS(MultiSet* set);
    int DeleteGT(BasicTrieNode* current, int i, char s[]);
    void CorrectPath(char s[]);
    int Delete_GT(BasicTrieNode *current);
    void Quit(BasicTrieNode* current);
    void Transform2SLL(SLL* set, WBLTNode* node); 
public:
    Trie();
    bool CheckTrie(int*);
    void Insert(char s[], int x);
    void Create(char s[]);
    void Delete(char s[]);
    void Merge(char s[], char t[]);
    void DeleteAll(char s[]);
    void DeleteElem(char s[], int x);
    void DeleteGEElem(char s[], int x);
    void DeleteMin(char s[]);
    void PrintMin(char s[]);
    void PrintMax(char s[]);
    void PrintNum(char s[]);
    void PrintCount(char s[], int x);
    void CountN();
    void CountNT();
    void PrintNumGT(char s[]);
    void DeleteGT(char s[]);
    void Check(char s[]);
    void Quit();
    //Helper functions below..
    BasicTrieNode* GetSet(char s[]);
    BasicTrieNode* GetRoot(){return root;}
    int useSLL, useWBLT;
    SLL* Transform2SLL(MultiSet* set);
    WBLT* Transform2WBLT(MultiSet* set);

};

#endif

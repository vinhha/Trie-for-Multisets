#ifndef ____WBLTNode__
#define ____WBLTNode__

#include <stdio.h>

class WBLTNode {
private:
    int data;
    int w;   // This is the s value in the slides.
    WBLTNode *leftchild;
    WBLTNode *rightchild;
public:
    bool Check(int*,int);
    int GetData()
    {return data;}
    WBLTNode* GetLeftChild(){return leftchild;}
    WBLTNode* GetRightChild(){return rightchild;}
    int GetW(){return w;}
    
};

#endif 

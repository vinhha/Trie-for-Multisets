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
    WBLTNode(){data = 0; w = 1; leftchild = 0; rightchild = 0;}
    WBLTNode(int x){data = x; w = 1; leftchild = 0; rightchild = 0;}
    bool Check(int*,int);
    int GetData(){return data;}
    WBLTNode* GetLeftChild(){return leftchild;}
    WBLTNode* GetRightChild(){return rightchild;}
    void SetLeftChild(WBLTNode* newLeft){leftchild = newLeft;}
    void SetRightChild(WBLTNode* newRight){rightchild = newRight;}
    int GetW(){return w;}
    void SetData(int x){data = x;};
    void SetW(int x){w = x;}
    

    
};

#endif 

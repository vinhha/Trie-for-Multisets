#ifndef ____SLLNode__
#define ____SLLNode__

#include <stdio.h>

class SLLNode {
private:
    int  data;
    SLLNode *next;
public:
    SLLNode(){data = 0; next = 0;};
    bool Check(int*,int);
    int GetData(){return data;}
    SLLNode* GetNext(){return next;}
    void SetNext(SLLNode* node){next = node;}
    void SetData(int x){data=x;}
    
};

#endif

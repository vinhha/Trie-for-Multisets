#ifndef ____SLLNode__
#define ____SLLNode__

#include <stdio.h>

class SLLNode {
private:
    int  data;
    SLLNode *next;
public:
    bool Check(int*,int);
    int GetData(){return data;}
    SLLNode* GetNext(){return next;}    
    
};

#endif

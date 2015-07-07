#ifndef ____SLL__
#define ____SLL__

#include <stdio.h>
#include "MultiSet.h"
#include "SLLNode.h"

class SLL: public MultiSet{
private:
    SLLNode* first;
public:
    SLL(){first = 0; SetPtr2PV(0);}
    int WhoAmI(){return 3;}
    SLLNode* GetFirst(){return first;}
    void SetFirst(SLLNode* ptr){first=ptr;}
    bool Check(int*);
    //Helper functions...
    void Place(int x);//Implement
    int GetLength();//Implement
    void TransformSet();//Implement
    virtual void DeleteSet();//Implement
};


#endif 

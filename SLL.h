#ifndef ____SLL__
#define ____SLL__

#include <stdio.h>
#include "MultiSet.h"
#include "SLLNode.h"

class SLL: public MultiSet{
private:
    SLLNode* first;
    void DeleteSet(SLLNode* current);
    SLLNode* Merge(SLLNode *a, SLLNode *b);
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
    void DeleteSet();//Implement
    void Merge(MultiSet* set);
    void DeleteElem(int x);
    void DeleteGEElem(int x);
    int GetMax();
    int GetCount(int x);

};


#endif 

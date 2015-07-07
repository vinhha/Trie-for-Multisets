#ifndef _MultiSet_h
#define _MultiSet_h

#include <stdio.h>
#include "SLLNode.h"
#include "WBLTNode.h"

class MultiSet{
private:
    MultiSet* ptr2previousVersion;
public:
    virtual int WhoAmI(){} //Leave these virtual functions defined as {}
    //for this base class.
    virtual SLLNode* GetFirst(){} //For technical reasons it needs to be defined this way.
    virtual void SetFirst(SLLNode* ptr){} //For technical reasons it needs to be defined this way.
    virtual void SetRoot(WBLTNode* ptr){}
    virtual WBLTNode* GetRoot(){}
    MultiSet* GetPtr2PV(){return ptr2previousVersion;}
    void SetPtr2PV(MultiSet* ptr){ptr2previousVersion=ptr;}
    virtual bool Check(int*){}
    //Helper functions...
    virtual void Place(int x);
    virtual int GetLength();
    virtual void TransformSet();
    virtual void DeleteSet(); 
};

#endif

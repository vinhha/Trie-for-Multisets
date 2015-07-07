#ifndef ____WBLT__
#define ____WBLT__

#include <stdio.h>
#include "MultiSet.h"
#include "WBLTNode.h"

class WBLT: public MultiSet{
private:
    WBLTNode*   root;
public:
    int WhoAmI(){return 4;}
    WBLT(){root=0; SetPtr2PV(0);}
    void SetRoot(WBLTNode* ptr) {root=ptr;}
    WBLTNode* GetRoot(){return root;}
    bool Check(int*);
    //Helper functions...
    void Place(int x);//Implement
    int GetLength();//Implement
    void TransformSet();//Implement
    virtual void DeleteSet();//Impliment

};

#endif

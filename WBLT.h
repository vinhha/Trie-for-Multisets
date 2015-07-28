#ifndef ____WBLT__
#define ____WBLT__

#include <stdio.h>
#include "MultiSet.h"
#include "WBLTNode.h"

class WBLT: public MultiSet{
private:
    WBLTNode*   root;
    void ClearSet(WBLTNode* node);
    WBLTNode* Meld(WBLTNode* node1, WBLTNode* node2);
    void Swap(WBLTNode* node);
    WBLTNode* Search(WBLTNode* current, int x);
    int DeleteGEElem(WBLTNode* current, int x);
    int GetMax(WBLTNode* current);
    void GetCount(WBLTNode* current, int x, int *count);
    bool DeleteGEElemChild(WBLTNode* child, int x);
public:
    int WhoAmI(){return 4;}
    WBLT(){root=0; SetPtr2PV(0);}
    ~WBLT(){DeleteSet();}
    void SetRoot(WBLTNode* ptr) {root=ptr;}
    WBLTNode* GetRoot(){return root;}
    bool Check(int*);
    //Helper functions...
    void Place(int x);
    int GetLength(){return root->GetW();}
    void DeleteSet();
    void DeleteElem(int x);
    void DeleteGEElem(int x);
    void DeleteMin(); 
    WBLTNode* Merge(WBLTNode* node1, WBLTNode* node2);
    int GetMax();
    int GetCount(int x);
};

#endif

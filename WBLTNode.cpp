#include "WBLTNode.h"

bool WBLTNode::Check(int* pcount, int value)
{int countl, countll;
    bool resp;
    int leftw, rightw;
    countl=0;
    leftw=rightw=0;
    resp=true;
    if(leftchild != 0) {resp=leftchild->Check(&countll,GetData())&&resp;
        leftw=leftchild->GetW();
        if(value > leftchild->GetData() ||
           value > 2000000000) return false;
        countl=countl+countll;
    }
    if(rightchild != 0) {resp=rightchild->Check(&countll,GetData())&&resp;
        rightw=rightchild->GetW();
        if(value > rightchild->GetData() ||
           value > 2000000000) return false;
        countl=countl+countll;
    }
    if(leftw < rightw) resp=false;
    *pcount=countl+1;
    return resp;
}

#include "WBLT.h"

bool WBLT::Check(int* pcount)
{bool temp;
    int countl;
    if(GetRoot() == 0) {*pcount=0; return true;}
    temp=root->Check(&countl,1);
    *pcount=countl;
    return temp;
}


//Helper functions...
void Place(int x){}
int GetLength(){}
void TransformSet(){}

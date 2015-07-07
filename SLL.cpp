#include "SLL.h"

bool SLL::Check(int* pcount)
{int countl;
    *pcount=0;
    if(GetFirst()== 0) return true;
    if(!GetFirst()->Check(&countl,1)) return false;
    *pcount = countl;
    return true;
}

//Helper functions...
void Place(int x){}
int GetLength(){}
void TransformSet(){}
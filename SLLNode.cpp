#include "SLLNode.h"

bool SLLNode::Check(int* pcount, int value)
{ int countl;
    if(GetData() < 1 || GetData() >2000000000 || value > GetData()) return false;
    if(GetNext() == 0) {*pcount=1; return true;}
    if(!GetNext()->Check(&countl,GetData())) return false;
    *pcount=countl+1;
    return true;
}
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
void SLL::Place(int x){
    SLLNode* current;
    SLLNode* new_node = new SLLNode();
    new_node->SetData(x);
    /* Special case for the head end */
    if (GetFirst() == NULL || GetFirst()->GetData() >= new_node->GetData())
    {
        new_node->SetNext(GetFirst());
        SetFirst(new_node);
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = GetFirst();
        while (current->GetNext() !=NULL &&
               current->GetNext()->GetData() < new_node->GetData())
        {
            current = current->GetNext();
        }
        new_node->SetNext(current->GetNext());
        current->SetNext(new_node);
    }
}
void SLL::TransformSet(){}

void SLL::DeleteSet(){
    
    SLLNode* current = GetFirst();
    if (current == 0) {
        return;
    }
    DeleteSet(current);
    
}

void SLL::DeleteSet(SLLNode* current){
    if (current->GetNext() == 0) {
        delete current;
        return;
    }
    DeleteSet(current->GetNext());
    delete current;
    return;
}

void SLL::Merge(MultiSet* set){
    SetFirst(Merge(GetFirst(), set->GetFirst()));
    set->SetFirst(0);
}

SLLNode* SLL::Merge(SLLNode* a, SLLNode* b){
    SLLNode* result = NULL;
    
    if (a == NULL){
        return b;
    }
    else if (b == NULL){
        return a;
    }
    
    if (a->GetData() <= b->GetData())
    {
        result = a;
        result->SetNext(Merge(a->GetNext(), b));
    }
    else
    {
        result = b;
        result->SetNext(Merge(a, b->GetNext()));
    }
    return result;
    
}

void SLL::DeleteElem(int x){

        SLLNode *pPre = NULL, *pDel = NULL;
        
        if (GetFirst()->GetData() == x) {
            pDel = GetFirst();
            SetFirst(pDel->GetNext());
            delete pDel;
            return;
        }
        
        pPre = GetFirst();
        pDel = GetFirst()->GetNext();
        
        /* traverse the list and check the value of each node */
        while (pDel != NULL) {
            if (pDel->GetData() == x) {
                /* Update the list */
                pPre->SetNext(pDel->GetNext());
                /* If it is the last node, update the tail */
                delete pDel; /* Here only remove the first node with the given value */
                break; /* break and return */
            }
            pPre = pDel;
            pDel = pDel->GetNext();
        }
}

void SLL::DeleteGEElem(int x){
    SLLNode *pPre = NULL, *pDel = NULL;
    
    if (GetFirst()->GetData() == x) {
        pDel = GetFirst();
        SetFirst(pDel->GetNext());
        delete pDel;
        return;
    }
    
    pPre = GetFirst();
    pDel = GetFirst()->GetNext();
    
    /* traverse the list and check the value of each node */
    while (pDel != NULL) {
        if (pDel->GetData() >= x) {
            /* Update the list */
            pPre->SetNext(pDel->GetNext());
            /* If it is the last node, update the tail */
            delete pDel; /* Here only remove the first node with the given value */
            pDel = pPre->GetNext();
        }
        else{
            pPre = pDel;
            pDel = pDel->GetNext();
        }
    }
}

int SLL::GetMax(){
    
    SLLNode* node = GetFirst();
    if (node == 0) {
        return 0; 
    }
    while (node->GetNext() != 0) {
        node = node->GetNext();
    }
    return node->GetData();
    
}

int SLL::GetLength(){
    
    SLLNode* node = GetFirst();
    if (node == 0) {
        return 0;
    }
    int i = 1;
    while (node->GetNext() != 0) {
        node = node->GetNext();
        i += 1;
    }
    return i;
    
}

int SLL::GetCount(int x){
    int i = 0;
    SLLNode* node = GetFirst();
    if (node == 0) {
        return 0;
    }
    if (node->GetData() == x) {
        int i = 1;
    }
    while (node->GetNext() != 0) {
        node = node->GetNext();
        if (node->GetData() == x) {
            i += 1;
        }
    }
    return i;
}













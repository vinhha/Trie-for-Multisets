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
  cout << x << endl;
        SLLNode *pPre = NULL, *pDel = NULL;
	if(GetFirst()){
        if (GetFirst()->GetData() == x) {
            pDel = GetFirst();
            SetFirst(pDel->GetNext());
            delete pDel;
            return;
        }
	if (GetFirst()->GetNext()){
        pPre = GetFirst();
        pDel = GetFirst()->GetNext();
        cout << "fukkk" << endl;
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
	}
}

void SLL::DeleteGEElem(int x){
  SLLNode *pPre = NULL, *pDel = NULL;
  if (GetFirst() == NULL) {
    return;
  }
  if (GetFirst()->GetData() >= x) {
    SLLNode* current = GetFirst();
    SLLNode* next;
 
    while (current != NULL) 
      {
	next = current->GetNext();
	delete current;
	current = next;
      }
   
    /* deref head_ref to affect the real head back
       in the caller. */
    SetFirst(0);

    return;
  }
    
  if (GetFirst()->GetNext()) {
    pPre = GetFirst();
    pDel = GetFirst()->GetNext();
    
    /* traverse the list and check the value of each node */
    while (pDel != NULL) {
      if (pDel->GetData() >= x) {
	SLLNode* current = pDel;
	SLLNode* next;

	while (current != NULL)
	  {
	    next = current->GetNext();
	    delete current;
	    current = next;
	  }

	/* deref head_ref to affect the real head back                              
	   in the caller. */
	pPre->SetNext(0);
	return;
      }
      else{
	pPre = pDel;
	pDel = pDel->GetNext();
      }
    }
  }
  return;
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
  if (!GetFirst()) {
    return 0;
  }
    SLLNode* node = GetFirst(); 
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













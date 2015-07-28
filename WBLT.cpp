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
void WBLT::Place(int x){
    root = Merge(new WBLTNode(x), root);
}


void WBLT::DeleteSet(){
    ClearSet(root);
    SetRoot(0);
}

void WBLT::ClearSet(WBLTNode* node){
    if (node != NULL)
    {
        ClearSet(node->GetLeftChild());
        ClearSet(node->GetRightChild());
        delete node;
    }
}

void WBLT::DeleteElem(int x){
    if (root != NULL) {
        WBLTNode* current = root;
        if (current->GetData() == x) {
            DeleteMin();
            return;
        }
        current = Search(current, x);
        if (current!= NULL) {
            if (current->GetLeftChild() && current->GetLeftChild()->GetData() == x) {
                WBLTNode* temp = current->GetLeftChild();
                current->SetLeftChild(Merge(current->GetLeftChild()->GetLeftChild(), current->GetLeftChild()->GetRightChild()));
                delete temp;
            }
            else if (current->GetRightChild() && current->GetRightChild()->GetData() == x) {
                WBLTNode* temp = current->GetRightChild();
                current->SetRightChild(Merge(current->GetRightChild()->GetLeftChild(), current->GetRightChild()->GetRightChild()));
                delete temp;
            }
        }
    }
   
}

WBLTNode* WBLT::Search(WBLTNode* current, int x){
    if (current == NULL || current->GetData() > x) {
        return NULL;
    }
    if (current->GetLeftChild() != NULL) {
        if(current->GetLeftChild()->GetData() == x){
            current->SetW(current->GetW() - 1); 
            return current;
        }
    }
    if (current->GetRightChild() != NULL) {
        if(current->GetRightChild()->GetData() == x){
            current->SetW(current->GetW() - 1);
            return current;
        }
    }
    WBLTNode* next = Search(current->GetLeftChild(), x);
    if (next != NULL) {
        current->SetW(current->GetW() - 1);
        return next;
    }
    next = Search(current->GetRightChild(), x);
    if (next != NULL) {
        current->SetW(current->GetW() - 1);
        return next;
    }
}

void WBLT::DeleteGEElem(int x){
    if (root->GetData() >= x) {
        ClearSet(root);
        SetRoot(0);
    }
    int j = DeleteGEElem(root, x);
}

int WBLT::DeleteGEElem(WBLTNode* current, int x){
    int r = 0;
    if (current->GetData() >= x) {
        r += current->GetW();
        ClearSet(current);
        current = 0;
        return r;
    }
    if (current->GetRightChild() != NULL){
        if (DeleteGEElemChild(current->GetRightChild(), x)) {
            r += current->GetRightChild()->GetW();
            ClearSet(current->GetRightChild());
            current->SetRightChild(0);
        }
        else{
            r += DeleteGEElem(current->GetRightChild(), x);
        }
    }
    if (current->GetLeftChild() != NULL){
        if (DeleteGEElemChild(current->GetLeftChild(), x)) {
            r += current->GetLeftChild()->GetW();
            ClearSet(current->GetLeftChild());
            current->SetLeftChild(0);
        }
        else{
            r += DeleteGEElem(current->GetLeftChild(), x);
        }
    }
    current->SetW(current->GetW() - r);
    return r;
}

bool WBLT::DeleteGEElemChild(WBLTNode* child, int x){
    if (child->GetData() >= x) {
        return true;
    }
    return false;
}

void WBLT::DeleteMin(){
    WBLTNode *old = root;
    root = Merge(root->GetLeftChild(), root->GetRightChild());
    delete old;
}

WBLTNode* WBLT::Merge(WBLTNode* node1, WBLTNode* node2){
    if (node1 == NULL)
        return node2;
    if (node2 == NULL)
        return node1;
    if (node1->GetData() < node2->GetData())
        return Meld(node1, node2);
    else
        return Meld(node2, node1);
}

WBLTNode* WBLT::Meld(WBLTNode* node1, WBLTNode* node2){
    if (node1->GetLeftChild() == NULL)
        node1->SetLeftChild(node2);
    else
    {
        node1->SetRightChild(Merge(node1->GetRightChild(), node2));
        if (node1->GetLeftChild()->GetW() < node1->GetRightChild()->GetW())
            Swap(node1);
    }
    if(node1->GetLeftChild() != NULL && node1->GetRightChild() != NULL)
        node1->SetW(node1->GetRightChild()->GetW() + node1->GetLeftChild()->GetW() + 1);
    else if(node1->GetLeftChild() == NULL && node1->GetRightChild() != NULL)
        node1->SetW(node1->GetRightChild()->GetW() + 1);
    else if(node1->GetLeftChild() != NULL && node1->GetRightChild() == NULL)
        node1->SetW(node1->GetLeftChild()->GetW() + 1);
    return node1;
}

void WBLT::Swap(WBLTNode* node){
    WBLTNode *temp = node->GetLeftChild();
    node->SetLeftChild(node->GetRightChild());
    node->SetRightChild(temp);
}

int WBLT::GetMax(){
    return GetMax(root);
}

int WBLT::GetMax(WBLTNode* current){
    if (current->GetRightChild() == NULL && current->GetLeftChild() == NULL) {
        return current->GetData();
    }
    int r = 0;
    int l = 0;
    if (current->GetRightChild() != NULL)
        r = GetMax(current->GetRightChild());
    if (current->GetLeftChild() != NULL)
        l = GetMax(current->GetLeftChild());
    if (r > l) {
        if (r > current->GetData()) {
            return r;
        }
        return current->GetData();
    }
    if (l > r) {
        if (l > current->GetData()) {
            return l;
        }
        return current->GetData();
    }
}

int WBLT::GetCount(int x){
    int count = 0; 
    GetCount(root, x, &count);
    return count; 
}

void WBLT::GetCount(WBLTNode* current, int x, int *count){
    if (current->GetData() == x) {
        (*count)++; 
    }
    if (current->GetRightChild() != NULL)
        GetCount(current->GetRightChild(), x, count);
    if (current->GetLeftChild() != NULL)
        GetCount(current->GetLeftChild(), x, count);

}







#include "Trie.h"
#include <string.h>
using namespace std;

//Constructor

Trie::Trie(){
    root = new TrieNode();
}

//Trie implementations
//************************************************************ Queued

void Trie::Create(char s[]){
    BasicTrieNode *current = root;
    int i = 0;
    while (s[i] != NULL) {
        int j = s[i] - 'a';
        if (current->GetPtr(j) == 0) {
            if (s[i+1] == NULL)
                current->SetPtr(j, new BasicTrieNode());
            else
                current->SetPtr(j, new TrieNode());
        }
        else if(current->GetPtr(j)->WhoAmI() == 1 && s[i + 1] != NULL){
            //change BasicTrieNode to TrieNode
            BasicTrieNode* trie = new TrieNode();
            trie->SetPtr2MS(current->GetPtr(j)->GetPtr2MS());
            BasicTrieNode *temp = current->GetPtr(j);
            delete temp;
            current->SetPtr(j, trie);

        }

        current = current->GetPtr(j);
        i = i + 1;
    }
    //
    //DEFINE OR CREATE MULTISET
    //
    if (current->GetPtr2MS() == 0) {
        MultiSet* ll = new SLL();
        current->SetPtr2MS(ll);
    }
    else{
        MultiSet* ll = new SLL();
        ll->SetPtr2PV(current->GetPtr2MS());
        current->SetPtr2MS(ll);
    }
    
    /*
     Function Description: 
     1. Set a pointer to the root of the current trie
     2. Traverse down the current trie as you iterate over s[]
        a. If the current trie node is of type BasicTrieNode, and we are not at the end of the word, then change the node to type TrieNode.
        b. If the next value in s[] does not have a defined trie node:
            i. If you are at the very end of s[], point the next value to a BasicTrieNode. 
            ii. Otherwise, point the next value to a TrieNode. 
     3. If s[] was not yet defined, then create a new MultiSet of type SLL
     4. Otherwise, create a new MultiSet of type SLL and make it the current Multiset
     */
}

//************************************************************ Queued for SLL

void Trie::Insert(char s[], int x){
    BasicTrieNode *set = GetSet(s);
    if (set != NULL && set->GetPtr2MS() != NULL) {
        if (set->GetPtr2MS()->GetLength() == 0) {
            SLLNode* value = new SLLNode();
            value->SetData(x);
            set->GetPtr2MS()->SetFirst(value);
        }
        else{
            if (set->GetPtr2MS()->GetLength() + 1 == useWBLT) {
                MultiSet *temp = set->GetPtr2MS();
                //********************************************
                MultiSet *a = Transform2WBLT(temp);
                //********************************************
                a->SetPtr2PV(temp->GetPtr2PV());
                set->SetPtr2MS(a);
                delete temp;
            }
            set->GetPtr2MS()->Place(x);
        }
    }
    else{
    }
    /*
     Function Description:
     1. Traverse to MultiSet s[]
     2. If the set is defined: 
        a. If the current set has no values then insert an SLLNode.
        b. Otherwise, get the length of the current set.
            i. Transform the set from SLL to WBLT if necessary. 
        c. Place x into the current set. 
     3. Finish
     */
}

//************************************************************ Transform to WBLT

WBLT* Trie::Transform2WBLT(MultiSet* set){
    SLLNode* current = set->GetFirst();
    if (current != 0) {
        WBLT* a = new WBLT();
        while (current) {
            a->Place(current->GetData());
            current = current->GetNext();
        }
        return a;
    }
    return 0;
    
}

//************************************************************ Transform to SLL

SLL* Trie::Transform2SLL(MultiSet* set){
    WBLTNode* node = set->GetRoot();
    if (node) {
        SLL* set = new SLL();
        Transform2SLL(set, node);
        return set;
    }
    return 0;
}

void Trie::Transform2SLL(SLL* set, WBLTNode* node){
    if (node == NULL) {
        return;
    }
    else{
        set->Place(node->GetData());
        Transform2SLL(set, node->GetLeftChild());
        Transform2SLL(set, node->GetRightChild());
    }
}

//************************************************************ Queued for SLL

void Trie::Delete(char s[]){
    BasicTrieNode *current = root;
    int i = 0;
    if (s[i] == NULL) {
        return;
    }
    bool j = Delete(s, i, current);
    
    /*
     Function Description:
     1. Set a pointer to the root of the trie
     2. If the input string is nothing then return
     3. Run Delete(char s[], int i, BasicTrieNode* current)
     */
}

bool Trie::Delete(char s[], int i, BasicTrieNode *current){
    if (current != 0) {
        if (s[i] == NULL) {
	  //Delete MultiSet -- Function should be defined in BasicTrieNode Class
           if (current->GetPtr2MS() != NULL) {
	      current->DeleteCurrentMS();
            }
            //Check if Node is empty or not, and if trie node has any further paths (if statement)
            //if its empty and no more multisets then delete node and return true
            if (current->CheckTrieNodeEmpty() /*|| current->WhoAmI() == 1*/) {
                delete current;
                return true;
            }
        }
        else if(current->WhoAmI() == 2){
            if (Delete(s, i + 1, current->GetPtr(s[i] - 'a'))) {
                current->SetPtr(s[i] - 'a', 0);
                if (i != 0 && current->CheckTrieNodeEmpty()) {
                    delete current;
                    return true;
                }
            }
            else {
                if (current->GetPtr(s[i] - 'a')) {
                    if (current->GetPtr(s[i] - 'a')->CheckPtrs() && current->GetPtr(s[i] - 'a')->WhoAmI() == 2 && current->GetPtr(s[i] - 'a')->GetPtr2MS() != 0){
                        BasicTrieNode* trie = new BasicTrieNode();
                        trie->SetPtr2MS(current->GetPtr(s[i] - 'a')->GetPtr2MS());
                        BasicTrieNode *temp = current->GetPtr(s[i] - 'a');
                        delete temp;
                        current->SetPtr(s[i] - 'a', trie);
                    }
                }
            }
        }
    }
    return false;
    /*
     Function Description:
     1. If the trie node is defined: 
        a. If we are at the end of the input string: 
            i. Delete the current version of the MultiSet 
            ii. If the trie node has no more MultiSets, and has no deeper paths delete the trie node and return true
        b. Otherwise, if the next trie node corresponding to the next character in s was deleted:
            i. Unset pointer to said trie node
            ii. If there are no more paths in the current trie node, and the current trie node has no multisets and it is not the first index of the input string, then delete the current trie node and return true.
     2. If nothing was returned yet return false
     */
    
}

//************************************************************ Queud for SLL

void Trie::Merge(char s[], char t[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set_1 = this->GetSet(s);
    //Run BasicTrieNode* down t[]
    BasicTrieNode* set_2 = this->GetSet(t);
    //If either do not exist exit with no-op
    if (set_1 == NULL || set_2 == NULL || set_1->GetPtr2MS() == NULL || set_2->GetPtr2MS() == NULL) {
        return;
    }
    
    //Give current version of s[] all elements of t[]
    //WRITE MERGE FUNCTIONS UNDER MULTISET CLASS FILES
    //(t[] will be empty)
    if (set_1->GetPtr2MS()->GetLength() + set_2->GetPtr2MS()->GetLength() >= useWBLT){
        if (set_1->GetPtr2MS()->WhoAmI() == 3 && set_2->GetPtr2MS()->WhoAmI() == 3){
            set_1->GetPtr2MS()->Merge(set_2->GetPtr2MS());
            MultiSet *temp = set_1->GetPtr2MS();
            //********************************************
            MultiSet *a = Transform2WBLT(temp);
            //********************************************
            a->SetPtr2PV(temp->GetPtr2PV());
            set_1->SetPtr2MS(a);
            delete temp;
        }
        else if (set_1->GetPtr2MS()->WhoAmI() == 3 && set_2->GetPtr2MS()->WhoAmI() == 4){
            MultiSet *temp = set_1->GetPtr2MS();
            //********************************************
            MultiSet *a = Transform2WBLT(temp);
            //********************************************
            a->SetPtr2PV(temp->GetPtr2PV());
            set_1->SetPtr2MS(a);
            delete temp;
            set_1->GetPtr2MS()->SetRoot(set_1->GetPtr2MS()->Merge(set_1->GetPtr2MS()->GetRoot(), set_2->GetPtr2MS()->GetRoot()));
            set_2->GetPtr2MS()->SetRoot(0);
        }
        else if (set_1->GetPtr2MS()->WhoAmI() == 4 && set_2->GetPtr2MS()->WhoAmI() == 3){
            MultiSet *temp = set_2->GetPtr2MS();
            //********************************************
            MultiSet *a = Transform2WBLT(temp);
            //********************************************
            a->SetPtr2PV(temp->GetPtr2PV());
            set_2->SetPtr2MS(a);
            delete temp;
            set_1->GetPtr2MS()->SetRoot(set_1->GetPtr2MS()->Merge(set_1->GetPtr2MS()->GetRoot(), set_2->GetPtr2MS()->GetRoot()));
            set_2->GetPtr2MS()->SetRoot(0);
        }
        else if (set_1->GetPtr2MS()->WhoAmI() == 4 && set_2->GetPtr2MS()->WhoAmI() == 4){
            set_1->GetPtr2MS()->SetRoot(set_1->GetPtr2MS()->Merge(set_1->GetPtr2MS()->GetRoot(), set_2->GetPtr2MS()->GetRoot()));
            set_2->GetPtr2MS()->SetRoot(0);
        }
    }
    
    
    else if (set_1->GetPtr2MS()->WhoAmI() == 3 && set_2->GetPtr2MS()->WhoAmI() == 3) {
        set_1->GetPtr2MS()->Merge(set_2->GetPtr2MS());
    }

    
}

//************************************************************ Queued for SLL

void Trie::DeleteAll(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = this->GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
    }
    //Recursively iterate down Multisets until ptr2previousVersion == NULL
    DeleteAllMS(set->GetPtr2MS());
    //Delete ptr2previousVersion and delete up the tree
    set->SetPtr2MS(0);
    Delete(s);
}

void Trie::DeleteAllMS(MultiSet* set){
    if (set->GetPtr2PV() == 0) {
        set->DeleteSet();
        delete set;
        return;
    }
    DeleteAllMS(set->GetPtr2PV());
    set->DeleteSet();
    delete set;
    return;
}
//************************************************************ Queued for SLL
void Trie::DeleteElem(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == NULL) {
        return; // No-op
    }
    //Search for x in current multiset of s
    //If x exists delete
    //Otherwise no-op
    set->GetPtr2MS()->DeleteElem(x);
}

//************************************************************ Queued for SLL

void Trie::DeleteGEElem(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL){
        return; // No-op
    }
    if (set->GetPtr2MS() == 0){
      return;
    }
    //Check through multiset
    //For each value in multiset > x delete element
    set->GetPtr2MS()->DeleteGEElem(x);
}

//************************************************************ Queued for SLL

void Trie::DeleteMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == NULL) {
        return; // No-op
    }
    //Find smallest element in current multiset and remove
    if (set->GetPtr2MS()->WhoAmI() == 3) {
      if (set->GetPtr2MS()->GetFirst() == NULL) {
	return;
      }
      SLLNode* til = set->GetPtr2MS()->GetFirst();
      set->GetPtr2MS()->SetFirst(til->GetNext());
      delete til;
    }
    if (set->GetPtr2MS()->WhoAmI() == 4) {
        set->GetPtr2MS()->DeleteMin();
        if (set->GetPtr2MS()->GetLength() < useSLL) {
            MultiSet *temp = set->GetPtr2MS();
            MultiSet *a = Transform2SLL(temp);
            a->SetPtr2PV(set->GetPtr2MS()->GetPtr2PV());
            set->SetPtr2MS(a);
            delete temp;
        }
    }

}

//************************************************************ Queued for SLL

void Trie::PrintMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
    }
    if (set->GetPtr2MS()->WhoAmI() == 3) {
        if (set->GetPtr2MS()->GetFirst() == 0) {
            return;
        }
    }
    if (set->GetPtr2MS()->WhoAmI() == 4) {
        if (set->GetPtr2MS()->GetRoot() == 0) {
            return;
        }
    }
    //Find smallest element in current multiset and print
    if (set->GetPtr2MS()->WhoAmI() == 3)
        cout << set->GetPtr2MS()->GetFirst()->GetData() << endl;
    else if (set->GetPtr2MS()->WhoAmI() == 4)
        cout << set->GetPtr2MS()->GetRoot()->GetData() << endl;
}

//************************************************************ Queued for SLL

void Trie::PrintMax(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
    }
    if (set->GetPtr2MS()->WhoAmI() == 3) {
        if (set->GetPtr2MS()->GetFirst() == 0) {
            return;
        }
    }
    if (set->GetPtr2MS()->WhoAmI() == 4) {
        if (set->GetPtr2MS()->GetRoot() == 0) {
            return;
        }
    }
    //Find largest element in current multiset and print
    MultiSet* ms = set->GetPtr2MS();
    cout << ms->GetMax() << endl; 
}

//************************************************************ Queued for SLL

void Trie::PrintNum(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    if (!set->GetPtr2MS()) {
      return; 
    }
    //Use a counter and iterate through elements in current multiset
    //Print counter
    MultiSet* ms = set->GetPtr2MS();
    cout << ms->GetLength() << endl;
}

//************************************************************ Queued for SLL

void Trie::PrintCount(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
    }
    //Initialize counter and iterate over current multiset
    //Increment counter for every occurence of x
    //Print counter value
    MultiSet* ms = set->GetPtr2MS();
    cout << ms->GetCount(x) << endl;
}

//************************************************************ Queued

void Trie::CountN(){
    BasicTrieNode* rootNode = this->root;
    int count = rootNode->Count();
    cout << count << endl;
}

//************************************************************ Queued

void Trie::CountNT(){
    BasicTrieNode* rootNode = this->root;
    int count = rootNode->CountAll();
    cout << count << endl; 
}

//************************************************************ Needs Implementation

void Trie::PrintNumGT(char s[]){
    int result = 0;
    BasicTrieNode *current = root;
    int i = 0;
    while (s[i] != NULL) {
        int j = (s[i] - 'a') + 1;
        for (j; j<TrieMaxElem; j++) {
            if (current->GetPtr(j) != 0) {
                if(current->GetPtr(j)->WhoAmI() == 1)
                    result += current->GetPtr(j)->CountMS();
                else
                    result += current->GetPtr(j)->CountGT(j);
            }
        }
        if (current->GetPtr(s[i] - 'a') == 0) {
            break;
        }
        else{
            current = current->GetPtr(s[i] - 'a');
            i = i + 1;
        }
        if (current->WhoAmI() == 2 && s[i] == NULL) {
            result += current->CountAll() - current->CountMS();
        }
    }

    
    cout << result << endl;
}



//************************************************************ Needs Implementation

void Trie::DeleteGT(char s[]){
    BasicTrieNode *current = root;
    int i = 0;
    if (s[i] == NULL) {
        return;
    }
    
    int j = DeleteGT(current, i, s);

}

int Trie::DeleteGT(BasicTrieNode* current, int i, char s[]){
    
    if (current != 0) {
        if (s[i] == NULL) {
            //Delete MultiSet -- Function should be defined in BasicTrieNode Class
            //Check if Node is empty or not, and if trie node has any further paths (if statement)
            //if its empty and no more multisets then delete node and return true
	  //r == 1 implies set parent node to 0 at this pointer location. 
	  //r == 2 implies change from trie node to basic trie node
            if (current->WhoAmI() == 2) {
                for (int i = 0; i < TrieMaxElem; i++) {
                    if (current->GetPtr(i) != 0) {
                        int r = Delete_GT(current->GetPtr(i));
                        if(r == 1){
                            current->SetPtr(i, 0);
                        }
                        if(r == 2){
                            BasicTrieNode* trie = new BasicTrieNode();
                            trie->SetPtr2MS(current->GetPtr(i)->GetPtr2MS());
                            BasicTrieNode *temp = current->GetPtr(i);
                            delete temp;
                            current->SetPtr(i, trie);
                        }
                    }
                }
                if(current->CheckPtrs() && current->GetPtr2MS() == 0){
		  delete current; 
		  return 1;
                }
                if (current->GetPtr2MS() != 0 && current->CheckPtrs()) {
                    return 2;
                }
	    }
            else if (current->GetPtr2MS() == 0 && current->WhoAmI() == 1) {
                delete current;
                return 1;
            }


        }
        else if (current->WhoAmI() == 2) {
            int j = (s[i] - 'a') + 1;
            for (j; j<TrieMaxElem; j++) {
                if (current->GetPtr(j) != 0) {
                    int r = Delete_GT(current->GetPtr(j));
                    if(r == 1){
                        current->SetPtr(j, 0);
                    }
                    if(r == 2){
                        BasicTrieNode* trie = new BasicTrieNode();
                        trie->SetPtr2MS(current->GetPtr(i)->GetPtr2MS());
                        BasicTrieNode *temp = current->GetPtr(i);
                        delete temp;
                        current->SetPtr(i, trie);
                    }

                }
            }
            int r = DeleteGT(current->GetPtr(s[i] - 'a'), i + 1, s);
            if (r == 1) {
                current->SetPtr(s[i] - 'a', 0);
                if (i != 0 && current->CheckPtrs() && current->GetPtr2MS() == 0) {
                    delete current;
                    return 1;
                }
            }
            else if (r == 2){
                BasicTrieNode* trie = new BasicTrieNode();
                trie->SetPtr2MS(current->GetPtr(s[i]-'a')->GetPtr2MS());
                BasicTrieNode *temp = current->GetPtr(i);
                delete temp;
                current->SetPtr(s[i]-'a', trie);
            }

        }
        
    }
    return 0;
}

int Trie::Delete_GT(BasicTrieNode *current){
    if (current->GetPtr2MS() != 0) {
        current->DeleteCurrentMS();
    }
    if (current->WhoAmI() == 2) {
        for (int i = 0; i < TrieMaxElem; i++) {
            if (current->GetPtr(i) != 0) {
                int r = Delete_GT(current->GetPtr(i));
                if(r == 1){
                    current->SetPtr(i, 0);
                }
                if(r == 2){
                    BasicTrieNode* trie = new BasicTrieNode();
                    trie->SetPtr2MS(current->GetPtr(i)->GetPtr2MS());
                    BasicTrieNode *temp = current->GetPtr(i);
                    delete temp;
                    current->SetPtr(i, trie);
                }
            }
        }
        if(current->CheckPtrs() && current->GetPtr2MS() == 0){
            delete current;
            return 1;
        }
        if (current->GetPtr2MS() != 0 && current->CheckPtrs()) {
            return 2;
        }
    }
    if (current->GetPtr2MS() == 0 && current->WhoAmI() == 1) {
        delete current;
        return 1;
    }
    return 0;
}
//************************************************************ Needs Implementation

void Trie::Check(char s[]){
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
    }

    int temp=0;
    if (set->GetPtr2MS()->Check(&temp)) cout << "True " << temp << " ";
        else cout << "False 0 ";
    cout << set->GetPtr2MS()->WhoAmI()-2 << endl;
}

//************************************************************ Needs Implementation

void Trie::Quit(){
    BasicTrieNode* current = root;
    for (int i = 0; i < TrieMaxElem; i++) {
        if (current->GetPtr(i) != 0) {
            Quit(current->GetPtr(i));
        }
    }
    delete current;

}

void Trie::Quit(BasicTrieNode* current){
    if (current->GetPtr2MS() != 0) {
        DeleteAllMS(current->GetPtr2MS());
    }
    if (current->WhoAmI() == 2) {
        for (int i = 0; i < TrieMaxElem; i++) {
            if (current->GetPtr(i) != 0) {
                Quit(current->GetPtr(i));
            }
        }
    }

    delete current;

}


//************************************************************

bool Trie::CheckTrie(int* count){
    if (root->CheckTrieNodeEmpty()) {
        return true; 
    }
    int countl;
    countl=0;
    bool result;
    result = root->CheckTrie(&countl);
    *count=countl;
    return result;
}

//************************************************************

//Helper functions below...

BasicTrieNode* Trie::GetSet(char s[]){
    BasicTrieNode* current = root;
    int i = 0;
    while (s[i] != NULL) {
      if(current->WhoAmI() == 1)
	return NULL;
      int j = s[i] - 'a';
      if (current->GetPtr(j) == 0) {
	return NULL;
      }
      else
	current = current->GetPtr(j);
      i = i + 1;
      
    }
    return current;
}













#include "Trie.h"

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
    if (set != NULL) {
        if (set->GetPtr2MS()->GetLength() == 0) {
            SLLNode* value = new SLLNode();
            value->SetData(x);
            set->GetPtr2MS()->SetFirst(value);
        }
        else{
            if (set->GetPtr2MS()->GetLength() == 8) {//Remember to change the 8!!!!!!!
                set->GetPtr2MS()->TransformSet();
            }
            set->GetPtr2MS()->Place(x);
        }
    }
    else{
        
        cout << "No-op" << endl;
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
            if (current->CheckTrieNodeEmpty() || current->WhoAmI() == 1) {
                delete current;
                return true;
            }
        }
        else {
            if (Delete(s, i + 1, current->GetPtr(s[i] - 'a'))) {
                current->SetPtr(s[i] - 'a', 0);
                if (i != 0 && current->CheckTrieNodeEmpty()) {
                    delete[] current;
                    return true;
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
    if (set_1 == NULL || set_2 == NULL) {
        cout << "No-op" << endl;
        return;
    }
    //Give current version of s[] all elements of t[]
    //WRITE MERGE FUNCTIONS UNDER MULTISET CLASS FILES
    //(t[] will be empty)
    if (set_1->GetPtr2MS()->WhoAmI() == 3 && set_2->GetPtr2MS()->WhoAmI() == 3) {
        set_1->GetPtr2MS()->Merge(set_2->GetPtr2MS());
    }
    MultiSet *ms_2 = set_2->GetPtr2MS();
    if (set_2->GetPtr2MS()->GetPtr2PV() != 0) {
        set_2->SetPtr2MS(set_2->GetPtr2MS()->GetPtr2PV());
    }
}

//************************************************************ Queued for SLL

void Trie::DeleteAll(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = this->GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Recursively iterate down Multisets until ptr2previousVersion == NULL
    if (set->GetPtr2MS() == 0) {
        return;
    }
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
    if (set == NULL) {
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
    if (set == NULL) {
        return; // No-op
    }
    //Check through multiset
    //For each value in multiset > x delete element
    set->GetPtr2MS()->DeleteGEElem(x);

}

//************************************************************ Queued for SLL

void Trie::DeleteMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Find smallest element in current multiset and remove
    SLLNode* til = set->GetPtr2MS()->GetFirst();
    set->GetPtr2MS()->SetFirst(til->GetNext());
    delete til;

}

//************************************************************ Queued for SLL

void Trie::PrintMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Find smallest element in current multiset and print
    cout << set->GetPtr2MS()->GetFirst()->GetData() << endl;
}

//************************************************************ Queued for SLL

void Trie::PrintMax(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL || set->GetPtr2MS() == 0) {
        return; // No-op
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
    //Use a counter and iterate through elements in current multiset
    //Print counter
    MultiSet* ms = set->GetPtr2MS();
    cout << ms->GetLength() << endl;
}

//************************************************************ Queued for SLL

void Trie::PrintCount(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
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
    cout << to_string(count) << endl;
}

//************************************************************ Queued

void Trie::CountNT(){
    BasicTrieNode* rootNode = this->root;
    int count = rootNode->CountAll();
    cout << count << endl; 
}

//************************************************************ Needs Implementation

void Trie::PrintNumGT(char s[]){
    //Ask the professor to clarify..?
}

//************************************************************ Needs Implementation

void Trie::DeleteGT(char s[]){
    //Once again, ask the professor to clarify
    //"...multisets with names after name < s >."
}

//************************************************************ Needs Implementation

void Trie::Check(char s[]){
    //Apparently appendix 3 has the code for this operation...?
    
}

//************************************************************ Needs Implementation

void Trie::Quit(){

}


//************************************************************

bool Trie::CheckTrie(int* count){
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
        int j = s[i] - 'a';
        if (current->GetPtr(j) == 0) {
            return NULL; //No-op..
        }
        else
            current = current->GetPtr(j);
        i = i + 1;

    }
    return current;
}

void Trie::PrintType(char s[]){
    BasicTrieNode* set = GetSet(s);
    if (set->GetPtr2MS()->WhoAmI() == 3) {
        cout << "SLL-TYPE" << endl;
    }
}












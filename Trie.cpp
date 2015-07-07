#include "Trie.h"

using namespace std;

//Constructor

Trie::Trie(){
    root = new TrieNode();
}

//Trie implementations
void Create(char s[]){
    BasicTrieNode *current = root;
    int i = 0;
    while (s[i] != 'O') {
        int j = s[i] - 'a';
        if(current->WhoAmI() == 1 && s[i + 1] != '\O'){
            //change BasicTrieNode to TrieNode
            TrieNode* trie = dynamic_cast<TrieNode*>(current);
            current = trie;
        }
        if (current->GetPtr(j) == 0) {
            if (s[i+1] == '\O')
                current->SetPtr(j, new BasicTrieNode());
            else
                current->SetPtr(j, new TrieNode());
        }
        current = current->GetPtr(j);
        i = i + 1;
    }
    //
    //DEFINE OR CREATE MULTISET
    //
    if (current->ptr2ms == 0) {
        MultiSet* ll = new SLL();
        current->ptr2ms = ll;
    }
    else{
        SLL* ll = new SLL();
        ll->ptr2previousVersion = current->ptr2ms;
        current->ptr2ms = ll;
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

void Trie::Insert(char s[], int x){
    BasicTrieNode *set = GetSet(s);
    if (set != NULL) {
        //
        //INSERT x INTO CURRENT VERSION OF MULTISET
        //
        if (set->ptr2ms->GetLength() == 0) {
            MultiSet* value = new SLLNode();
            value->data = x;
            set->ptr2ms->SetFirst(value);
        }
        else{
            if (set->ptr2ms->GetLength() == /*SLL threshold*/) {
                set->ptr2ms->Transform();
            }
            set->ptr2ms->Place(x);
        }
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

void Trie::Delete(char s[]){
    BasicTrieNode *current = root;
    int i = 0;
    if (s[i] == 'O') {
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
        if (s[i] == '\O') {
            //Delete MultiSet -- Function should be defined in BasicTrieNode Class
            current->DeleteCurrentMS();
            //Check if Node is empty or not, and if trie node has any further paths (if statement)
            //if its empty and no more multisets then delete node and return true
            if (current->CheckTrieNodeEmpty()) {
                delete current;
                return true;
            }
        }
        else {
            if (Delete(s, i + 1, current->GetPtr(x[i] - 'a'))) {
                current->SetPtr(s[i] - 'a', 0);
                if (i != 0 && current->CheckTrieNodeEmpty()) {
                    delete current;
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

void Merge(char s[], char t[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set_1 = GetSet(s);
    //Run BasicTrieNode* down t[]
    BasicTrieNode* set_2 = GetSet(t);
    //If either do not exist exit with no-op
    if (set_1 == NULL || set_2 == NULL) {
        cout << "No-op" << endl;
        return;
    }
    //Give current version of s[] all elements of t[]
    //WRITE MERGE FUNCTIONS UNDER MULTISET CLASS FILES
    //(t[] will be empty)

}

void DeleteAll(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Recursively iterate down Multisets until ptr2previousVersion == NULL
    //Delete ptr2previousVersion and delete up the tree
    
}

void DeleteElem(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Search for x in current multiset of s
    //If x exists delete
    //Otherwise no-op
}

void DeleteGEElem(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Check through multiset
    //For each value in multiset > x delete element

}

void DeleteMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Find smallest element in current multiset and remove

}

void PrintMin(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Find smallest element in current multiset and print
    
}

void PrintMax(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Find largest element in current multiset and print
}

void PrintNum(char s[]){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Use a counter and iterate through elements in current multiset
    //Print counter
}

void PrintCount(char s[], int x){
    //Set BasicTrieNode* to s[]
    BasicTrieNode* set = GetSet(s);
    if (set == NULL) {
        return; // No-op
    }
    //Initialize counter and iterate over current multiset
    //Increment counter for every occurence of x
    //Print counter value
}

void CountN(){
    //This one will be a bit tricky.....
}

void CountNT(){
    //This one will also be a bit tricky.....
}

void PrintNumGT(char s[]){
    //Ask the professor to clarify..?
}

void DeleteGT(char s[]){
    //Once again, ask the professor to clarify "...multisets with names after name < s >."
}

void Check(char s[]){
    //Apparently appendix 3 has the code for this operation...?
    
}

void Quit(){

}


bool Trie::CheckTrie(int* count){
    int countl;
    countl=0;
    bool result;
    result = root->CheckTrie(&countl);
    *count=countl;
    return result;
}



//Helper functions below...

BasicTrieNode* Trie::GetSet(char s[]){
    BasicTrieNode* current = root;
    int i = 0;
    while (s[i] != 'O') {
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















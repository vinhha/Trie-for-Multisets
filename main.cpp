#include <iostream>
#include <string>
#include "Trie.h"
#include "BasicTrieNode.h"
#include "MultiSet.h"
#include "SLL.h"
#include "SLLNode.h"
#include "TrieNode.h"
#include "WBLT.h"
#include "WBLTNode.h"

using namespace std;

int main(void)
{
    // Test for BasicTrieNodes and TrieNodes
    BasicTrieNode  *bpointer,*pointer,*ptr;
    ptr = new TrieNode();
    bpointer = new BasicTrieNode();
    cout << bpointer->WhoAmI()<< endl;//
    pointer = new TrieNode();
    cout << pointer->WhoAmI()<< endl;//
    ptr->SetPtr(1,bpointer);
    ptr->SetPtr(3,pointer);
    cout << ptr->GetPtr(1)->WhoAmI() << endl;//
    cout << ptr->GetPtr(3)->WhoAmI() << endl;//
    
    // Test for SLL and WBLT
    MultiSet *ms1, *ms2;
    ms1=new SLL();
    ms2=new WBLT();
    cout << ms1->WhoAmI() << endl;
    cout << ms2->WhoAmI() << endl;
    SLLNode *pt1;
    WBLTNode *pt2;
    pt1= new SLLNode();
    pt2= new WBLTNode();
    cout <<  ms1->WhoAmI() << endl;
    cout <<  ms2->WhoAmI() << endl;
    ms1->SetFirst(pt1);
    ms2->SetRoot(pt2);
    
    
    // Using CheckTrie
    // int temp;
    // Trie t;
    // Assume that t has been initialized correctly
    // temp=0;
    // if(t.GetRoot()->CheckTrie(&temp)) cout << "True " << temp << endl;
    //           else cout << "False 0" << endl;
    // MultiSet  *q;
    // temp=0;
    // Assume that q points to a MultiSet (SLL or WBLT)
    //  if (q->Check(&temp)) cout << "True " << temp << " ";
    //        else cout << "False 0 ";
    //  cout << q->WhoAmI()-2 << endl;
    //
    return 0;
}
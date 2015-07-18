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
    string oper,s,t;
    Trie* trie = new Trie();
    int x;
    while(1 == 1)
    { cin >> oper;
        
        if (oper == "Quit") {// delete everything then end program
            break;
        }
        
        else if (oper == "Insert")
        {   cin >> s >> x;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->Insert(cstr, x);
        }
        
        else if (oper == "Create")
        {   cin >> s;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->Create(cstr);
        }
        
        else if (oper == "Delete")
        {   cin >> s;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->Delete(cstr);
        }
        
        else if (oper == "CheckTrie")
        {
            int temp;
            // Assume that t has been initialized correctly
            temp=0;
            if(trie->GetRoot()->CheckTrie(&temp)) cout << "True " << temp << endl;
                       else cout << "False 0" << endl;
        }
        
        else if (oper == "CountN")
        {
            trie->CountN();
        }
        
        else if (oper == "CountNT")
        {
            trie->CountNT();
        }
        
        else if (oper == "DeleteAll")
        {
            cin >> s;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->DeleteAll(cstr);
        }
        
        else if (oper == "PrintNum")
        {
            cin >> s;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->PrintNum(cstr);
        }
        
        else if (oper == "PrintType")
        {
            cin >> s;
            char * cstr = new char [s.length()+1];
            std::strcpy (cstr, s.c_str());
            trie->PrintType(cstr);
        }
        // ...
    }
    return 0;
}

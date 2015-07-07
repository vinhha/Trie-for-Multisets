# platform / project specific compiler, flags, etc.
#
CXX=g++
CXXFLAGS=-W -Wall -pedantic -g

# project specifics
#
APP=executeit
OBJS = main.o BasicTrieNode.o TrieNode.o MultiSet.o SLL.o SLLNode.o Trie.o WBLT.o WBLTNode.o


# make commands - all, clean
#
all: $(APP)

$(APP):	$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:	
	/bin/rm -f *.o *~* $(APP)
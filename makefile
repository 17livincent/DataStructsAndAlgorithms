CXX=g++
CXXFLAGS=-Wall -g

TARGETS=linkedlist binarytree

all: $(TARGETS)

linkedlist: linkedlist.cpp
	$(CXX) $(CXXFLAGS) -o linkedlist linkedlist.cpp

binarytree: binarytree.cpp
	$(CXX) $(CXXFLAGS) -o binarytree binarytree.cpp

clean:
	rm -f $(TARGETS) *.o
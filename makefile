CXX=g++
CXXFLAGS=-Wall -g

TARGETS=linkedlist binarytree graph

all: $(TARGETS)

linkedlist: linkedlist.cpp
	$(CXX) $(CXXFLAGS) -o linkedlist linkedlist.cpp

binarytree: binarytree.cpp
	$(CXX) $(CXXFLAGS) -o binarytree binarytree.cpp

graph: graph.cpp
	$(CXX) $(CXXFLAGS) -o graph graph.cpp

clean:
	rm -f $(TARGETS) *.exe *.o
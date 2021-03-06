/**
 *  @file graph.cpp
 *  @author Vincent Li
 *  Implementation of a graph and associated algorithms.
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cassert>
#include "graph.h"

template <typename T>
void Graph::addVertice(AdjacencyList(T)* adjListPtr, GraphNode<T>* verticePtr) {
    AdjacencyList(T) a = *adjListPtr;
    Edges(char) edges;
    a.insert(make_pair(verticePtr, edges));
    *adjListPtr = a;
}

template <typename T>
void Graph::addEdge(AdjacencyList(T)* adjListPtr, GraphNode<T>* v1Ptr, GraphNode<T>* v2Ptr, double cost, bool directed) {
    AdjacencyList(T) a = *adjListPtr;

    // Find v1 in a
    auto v1Loc = a.find(v1Ptr);
    assert(v1Loc != a.end());

    // Add an edge from v1 to v2
    v1Loc->second.insert(std::make_pair(v2Ptr, cost));

    if(!directed) { // If undirected
        // Find v2 in a
        auto v2Loc = a.find(v2Ptr);
        assert(v2Loc != a.end());

        // Add an edge from v2 to v1
        v2Loc->second.insert(std::make_pair(v1Ptr, cost));
    }

    *adjListPtr = a;
}

template<typename T>
void Graph::printAdjList(AdjacencyList(T)* adjListPtr) {
    AdjacencyList(T) adjList = *adjListPtr;
    std::cout << "Adjacency List:" << std::endl;
    std::cout << "Size: " << adjList.size() << std::endl;
    for(auto itr1 = adjList.begin(); itr1 != adjList.end(); itr1++) {
        // Print node
        std::cout << itr1->first->value << ": ";
        // Print edges
        if(!itr1->second.empty()) {
            std::cout << "[";
            for(auto itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++) {
                std::cout << " (" << itr2->first->value << "," << itr2->second << ")"; 
            }
            std::cout << " ]";
        }
        else {
            std::cout << "No edges";
        }
        std::cout << std::endl;
    }
}

template <typename T>
GraphNode<T>* Graph::depthFirstSearch(AdjacencyList(T)* adjListPtr, GraphNode<T>* start, T goal) {
    AdjacencyList(T) adjList = *adjListPtr;
    // Stack
    std::stack<GraphNode<T>*> stack;
    // List of visited nodes
    std::list<GraphNode<T>*> visited;
    
    bool goalFound = false;

    // Push the start node to the stack.
    stack.push(start);
    // Mark start as visited.
    visited.push_back(start);

    GraphNode<T>* scan = NULL;
    GraphNode<T>* result = NULL;

    while(!stack.size() == 0 and !goalFound) {
        scan = stack.top();
        stack.pop();
        // If this is the goal, stop.
        assert(scan != NULL);
        if(scan->value == goal) {
            result = scan;
            goalFound = true;
        }
        else {
            // Find this node's location in the adjacency list.
            auto neighbors = adjList.find(scan);
            assert(neighbors != adjList.end());
            // Iterate through the node's neighbors.  Add to stack if not visited.
            for(auto neighbor = neighbors->second.begin(); neighbor != neighbors->second.end(); neighbor++) {
                GraphNode<T>* thisNeighbor = neighbor->first;

                // See if this neighbor has been visited.
                bool inVisited = false;
                for(GraphNode<T>* test : visited) {
                    if(thisNeighbor == test) {
                        inVisited = true;
                        break;
                        std::cout << "Visited" << std::endl;
                    }
                }

                // Add to stack and visited if not.
                if(!inVisited) {
                    // Add to stack and visited.
                    stack.push(thisNeighbor);
                    visited.push_back(thisNeighbor);
                }
            }
        }
    }
    return result;
}

template <typename T>
GraphNode<T>* Graph::breadthFirstSearch(AdjacencyList(T)* adjListPtr, GraphNode<T>* start, T goal) {
    AdjacencyList(T) adjList = *adjListPtr;
    std::queue<GraphNode<T>*> queue;
    // List of visited nodes
    std::list<GraphNode<T>*> visited;
    
    bool goalFound = false;

    // Push the start node to the stack.
    queue.push(start);
    // Mark start as visited.
    visited.push_back(start);

    GraphNode<T>* scan = NULL;
    GraphNode<T>* result = NULL;

    while(!queue.size() == 0 and !goalFound) {
        scan = queue.front();
        queue.pop();
        // If this is the goal, stop.
        assert(scan != NULL);
        if(scan->value == goal) {
            result = scan;
            goalFound = true;
        }
        else {
            // Find this node's location in the adjacency list.
            auto neighbors = adjList.find(scan);
            assert(neighbors != adjList.end());
            // Iterate through the node's neighbors.  Add to stack if not visited.
            for(auto neighbor = neighbors->second.begin(); neighbor != neighbors->second.end(); neighbor++) {
                GraphNode<T>* thisNeighbor = neighbor->first;

                // See if this neighbor has been visited.
                bool inVisited = false;
                for(GraphNode<T>* test : visited) {
                    if(thisNeighbor == test) {
                        inVisited = true;
                        break;
                        std::cout << "Visited" << std::endl;
                    }
                }

                // Add to stack and visited if not.
                if(!inVisited) {
                    // Add to stack and visited.
                    queue.push(thisNeighbor);
                    visited.push_back(thisNeighbor);
                }
            }
        }
    }
    return result;
    
}

int main(int argc, char** argv) {    
    /*
        Undirected graph
        A0: (B, 4)  (H, 8)
        B1: (A, 4)  (C, 8)  (H, 11)
        C2: (B, 8)  (I, 2)  (F, 4)  (D, 7)
        D3: (C, 7)  (F, 14) (E, 9)
        E4: (D, 9)  (F, 10)
        F5: (D, 14) (E, 10) (C, 4) (G, 2)
        G6: (F, 2)  (H, 1)  (I, 6)
        H7: (B, 11) (G, 1)  (I, 7)
        I8: (C, 2)  (G, 6)  (H, 7)
    */

    Graph graph;
    AdjacencyList(char) list;

    // Create nodes
    GraphNode<char> a = {'A'};
    GraphNode<char> b = {'B'};
    GraphNode<char> c = {'C'};
    GraphNode<char> d = {'D'};
    GraphNode<char> e = {'E'};
    GraphNode<char> f = {'F'};
    GraphNode<char> g = {'G'};
    GraphNode<char> h = {'H'};
    GraphNode<char> i = {'I'};

    // Add nodes to adjacency list
    graph.addVertice(&list, &a);
    graph.addVertice(&list, &b);
    graph.addVertice(&list, &c);
    graph.addVertice(&list, &d);
    graph.addVertice(&list, &e);
    graph.addVertice(&list, &f);
    graph.addVertice(&list, &g);
    graph.addVertice(&list, &h);
    graph.addVertice(&list, &i);
    graph.printAdjList(&list);

    // Add edges to adjacency list
    graph.addEdge(&list, &a, &b, 4, true); graph.addEdge(&list, &a, &h, 8, true);
    graph.addEdge(&list, &b, &a, 4, true); graph.addEdge(&list, &b, &c, 8, true); graph.addEdge(&list, &b, &h, 11, true);
    graph.addEdge(&list, &c, &b, 8, true); graph.addEdge(&list, &c, &i, 2, true); graph.addEdge(&list, &c, &f, 4, true); graph.addEdge(&list, &c, &d, 7, true);
    graph.addEdge(&list, &d, &c, 7, true); graph.addEdge(&list, &d, &f, 14, true); graph.addEdge(&list, &d, &e, 9, true);
    graph.addEdge(&list, &e, &d, 9, true); graph.addEdge(&list, &e, &f, 10, true);
    graph.addEdge(&list, &f, &d, 14, true); graph.addEdge(&list, &f, &e, 10, true); graph.addEdge(&list, &f, &c, 4, true); graph.addEdge(&list, &f, &g, 2, true);
    graph.addEdge(&list, &g, &f, 2, true); graph.addEdge(&list, &g, &h, 1, true); graph.addEdge(&list, &g, &i, 6, true);
    graph.addEdge(&list, &h, &b, 11, true); graph.addEdge(&list, &h, &g, 1, true); graph.addEdge(&list, &h, &i, 7, true);
    graph.addEdge(&list, &i, &c, 2, true); graph.addEdge(&list, &i, &g, 6, true); graph.addEdge(&list, &i, &h, 7, true);
    graph.printAdjList(&list);

    // Test DFS
    GraphNode<char>* dfsB = graph.depthFirstSearch(&list, &a, 'B');
    assert(dfsB != NULL);
    std::cout << "DFS found: " << dfsB->value << std::endl;
    GraphNode<char>* dfsI = graph.depthFirstSearch(&list, &a, 'I');
    assert(dfsI != NULL);
    std::cout << "DFS found: " << dfsI->value << std::endl;
    GraphNode<char>* dfsH = graph.depthFirstSearch(&list, &a, 'H');
    std::cout << "DFS found: " << dfsH->value << std::endl;

    // Test BFS
    GraphNode<char>* bfsB = graph.breadthFirstSearch(&list, &a, 'B');
    assert(bfsB != NULL);
    std::cout << "BFS found: " << bfsB->value << std::endl;
    GraphNode<char>* bfsI = graph.breadthFirstSearch(&list, &a, 'I');
    assert(bfsI != NULL);
    std::cout << "BFS found: " << bfsI->value << std::endl;
    GraphNode<char>* bfsH = graph.breadthFirstSearch(&list, &a, 'H');
    std::cout << "BFS found: " << bfsH->value << std::endl;

    return 0;
}

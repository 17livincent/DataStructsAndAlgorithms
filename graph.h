/**
 *  @file graph.h
 *  @author Vincent Li
 *  Implementation of a graph and associated algorithms.
 */

#pragma once
#ifndef GRAPH
#define GRAPH

#include <cstddef>
#include <map>
#include <vector>
#include <utility>

#define Edges(T)   std::map<GraphNode<T>*, double>
#define AdjacencyList(T)    std::map<GraphNode<T>*, std::map<GraphNode<T>*, double>>   // A map of node type to map of edges (type to cost)

template <typename T>
struct GraphNode {
    T value;
};

class Graph {
    public:
        /**
         *  Add a vertice to the given adjacency list.
         */
        template <typename T>
        void addVertice(AdjacencyList(T)* adjListPtr, GraphNode<T>* vertice);

        /**
         *  Add an edge to the given adjacency list. 
         *  The edge can directed (true) or undirected (false).
         */
        template <typename T>
        void addEdge(AdjacencyList(T)* adjListPtr, GraphNode<T>* v1Ptr, GraphNode<T>* v2Ptr, double cost, bool directed);

        /**
         *  Print the adjacency list.
         */
        template <typename T>
        void printAdjList(AdjacencyList(T)* adjListPtr);
};

#endif  // GRAPH
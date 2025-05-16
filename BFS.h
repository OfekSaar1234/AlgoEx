#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include "DirGraph.h"
#include "EdgeType.h"

#define INFINITY -1
#define PARENTLESS -1 
using namespace std;


class BFS {
private:

    int numVertices;      // Total number of vertices
    vector<int> d;        // Distance array
    vector<int> p;        // Parent array
   
   void printEdgeType(EdgeType edgeType) const;
   void printOperations(const vector<EdgeType>& operations, int numOfOperations) const;
   bool isReachable(const pair<int, int>& goalVertex, DirGraph& graph) const
   {
	   return d[goalVertex.first * (graph.getS() + 1) + goalVertex.second] != INFINITY;
   }

public:
    BFS(DirGraph& graph) : numVertices((graph.getL() + 1)* (graph.getS() + 1)), d(numVertices, INFINITY), p(numVertices, PARENTLESS) {}

    void runFirstImplementation(DirGraph& graph, pair<int, int> startVertex);
    void printPath(const pair<int, int>& goalVertex, DirGraph& graph) const;

};

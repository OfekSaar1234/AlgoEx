#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include "DirGraphImp1.h"
#include "EdgeType.h"
#include "Utils.h"

#define INFINITY -1
#define PARENTLESS -1 
using namespace std;


class BFSIm1 {
private:

    int numVertices;      // Total number of vertices
    vector<int> d;        // Distance array
    vector<int> p;        // Parent array
   
   bool isReachable(const pair<int, int>& goalVertex, DirGraphImp1& graph) const
   {
	   return d[goalVertex.first * (graph.getS() + 1) + goalVertex.second] != INFINITY;
   }

public:
    BFSIm1(DirGraphImp1& graph) : numVertices((graph.getL() + 1)* (graph.getS() + 1)), d(numVertices, INFINITY), p(numVertices, PARENTLESS) {}

    void runFirstImplementation(DirGraphImp1& graph, pair<int, int> startVertex);
    void printPath(const pair<int, int>& goalVertex, DirGraphImp1& graph) const;

};

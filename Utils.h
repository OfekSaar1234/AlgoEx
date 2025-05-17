#pragma once

#include <vector>
#include <iostream>
#include <utility>
#include "EdgeType.h"

using namespace std;

class Utils
{
public:
	static int getIndex(pair<int, int> vertex, int smallJarAmount)  { return vertex.first * (smallJarAmount + 1) + vertex.second; } // to get the index of the vertex in the vector
	static pair<int, int> getVertex(int index, int smallJarAmount)  { return make_pair(index / (smallJarAmount + 1), index % (smallJarAmount + 1)); } // to get the vertex from the index
	static void printOperations(const vector<EdgeType>& operations, int numOfOperations);
	static void printEdgeType(EdgeType edgeType);

};


#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
#include <utility> // for std::pair

using namespace std;

class DirGraph
{
private:
	
	int m_L;
	int m_S;
	int m_numVertices;
	unordered_map<pair<int, int> , list<pair<int, int>>> m_AdjList;

	void addVerticesToGraph();
	void addVertexToGraph(pair<int, int> vertex);

	void addEdge(pair<int, int> u, pair<int, int> v);
	void addEdgeFillLargeJug();
	void addEdgeFillSmallJug();
	void addEdgeEmptyLargeJug();
	void addEdgeEmptySmallJug();
	void addEdgePourLargeJugToSmallJug();
	void addEdgePourSmallJugToLargeJug();

public:
	
	DirGraph(int L, int S) : m_L(L), m_S(S) {}

	void MakeEmptyGraph(int numOfVertices);
	void FillGraphEdges();
	list<pair<int, int>> getAdjList(pair<int, int> vertex);






};


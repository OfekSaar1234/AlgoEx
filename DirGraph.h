#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
#include <utility>
#include "Vertex.h"

using namespace std;

class DirGraph
{
private:
	
	int m_L;
	int m_S;
	int m_numVertices;

	vector<Vertex> vertices;

	void addVerticesToGraph(); // //////////////
	void addVertexToGraph(pair<int, int> vertex);///////////////

	void addEdge(Vertex from, Vertex to);
	void addEdgeFillLargeJug();
	void addEdgeFillSmallJug();
	void addEdgeEmptyLargeJug();
	void addEdgeEmptySmallJug();
	void addEdgePourLargeJugToSmallJug();
	void addEdgePourSmallJugToLargeJug();
	void MakeEmptyGraph(int numOfVertices);////////
	void FillGraphEdges();

public:
	
	DirGraph(int L, int S) : m_L(L), m_S(S) ////////
	{
		m_numVertices = (L + 1) * (S + 1);
		MakeEmptyGraph(m_numVertices);///////////
		FillGraphEdges();
	}

	
	list<Vertex> getAdjList(Vertex vertex);


};


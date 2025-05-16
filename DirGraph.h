#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
#include <utility>
#include "Vertex.h"
#include "EdgeType.h"

using namespace std;

class DirGraph
{
private:
	
	int m_L;
	int m_S;
	int m_numVertices;


	vector<list<pair<pair<int, int>, EdgeType>>> m_AdjList; 

	//void addVerticesToGraph(); // //////////////
	//void addVertexToGraph(pair<int, int> vertex);

	void addEdge(pair<int,int> from, pair<int, int> to, EdgeType edgeType);
	void addEdgeFillLargeJug();
	void addEdgeFillSmallJug();
	void addEdgeEmptyLargeJug();
	void addEdgeEmptySmallJug();
	void addEdgePourLargeJugToSmallJug();
	void addEdgePourSmallJugToLargeJug();
	void MakeEmptyGraph(int numOfVertices);
	void FillGraphEdges();

	void sortAdjList();

public:
	
	DirGraph(int L, int S) : m_L(L), m_S(S) 
	{
		m_numVertices = (L + 1) * (S + 1);
		MakeEmptyGraph(m_numVertices);
		FillGraphEdges();
	}

	EdgeType getEdge(pair<int, int> from, pair<int, int> to) const
	{
		for (const auto& neighbor : m_AdjList[getIndex(from)])
		{
			if (neighbor.first == to)
			{
				return neighbor.second;
			}
		}
	}

	int getL() const { return m_L; }
	int getS() const { return m_S; }
	int getIndex(pair<int, int> vertex) const { return vertex.first * (m_S + 1) + vertex.second; } // to get the index of the vertex in the vector
	pair<int, int> getVertex(int index) const { return make_pair(index / (m_S + 1), index % (m_S + 1)); } // to get the vertex from the index

	const list<pair<pair<int, int>, EdgeType>>& getAdjList(pair<int, int> vertex) const { return m_AdjList[getIndex(vertex)]; }

};


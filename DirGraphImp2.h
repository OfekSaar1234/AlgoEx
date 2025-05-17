#pragma once

#include <iostream>
#include <unordered_set>
#include "EdgeType.h"

using namespace std;

class DirGraphImp2
{
private:
	
	int m_L;
	int m_S;
	int m_numVertices;

	unordered_set<int> m_visited;

	pair<pair<int, int>, EdgeType> getNeighborFillLargeJug(const pair<int, int>& vertex) const;
	pair<pair<int, int>, EdgeType> getNeighborFillSmallJug(const pair<int, int>& vertex) const;
	pair<pair<int, int>, EdgeType> getNeighborEmptyLargeJug(const pair<int, int>& vertex) const;
	pair<pair<int, int>, EdgeType> getNeighborEmptySmallJug(const pair<int, int>& vertex) const;
	pair<pair<int, int>, EdgeType> getNeighborPourLargeJugToSmallJug(const pair<int, int>& vertex) const;
	pair<pair<int, int>, EdgeType> getNeighborPourSmallJugToLargeJug(const pair<int, int>& vertex) const;

public:

	DirGraphImp2(int l, int s) : m_L(l), m_S(s)
	{
		m_numVertices = (l + 1) * (s + 1);
	}

	int getL() const { return m_L; }
	int getS() const { return m_S; }
	int getNumVertices() const { return m_numVertices; }

	void markVisited(int vertex)
	{
		m_visited.insert(vertex);
	}

	bool vertexBeenVisited(const int vertex) const
	{
		return m_visited.find(vertex) != m_visited.end();
	}

	void CalculateAdjList(vector<pair<pair<int, int>, EdgeType>>& adjList, const pair<int, int>& vertex) const
	{
		if (vertex.first != m_L)
			adjList.push_back(getNeighborFillLargeJug(vertex));

		if (vertex.second != m_S)
			adjList.push_back(getNeighborFillSmallJug(vertex));

		if (vertex.first != 0)
			adjList.push_back(getNeighborEmptyLargeJug(vertex));

		if (vertex.second != 0)
			adjList.push_back(getNeighborEmptySmallJug(vertex));

		if (vertex.first != 0 && vertex.second != m_S)
			adjList.push_back(getNeighborPourLargeJugToSmallJug(vertex));

		if (vertex.second != 0 && vertex.first != m_L)
			adjList.push_back(getNeighborPourSmallJugToLargeJug(vertex));
	}


};


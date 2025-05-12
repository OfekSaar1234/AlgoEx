#include "DirGraph.h"

void DirGraph::MakeEmptyGraph(int numOfVertices)
{
	while (numOfVertices < 1)
	{
		cout << "Invalid Input! Please enter a positive whole number.";
		cin >> numOfVertices;
	}

	m_numVertices = numOfVertices;
	m_AdjList.clear();

	addVerticesToGraph();
}

void DirGraph::FillGraphEdges()
{
}

void DirGraph::addVerticesToGraph()
{
	for (int i = 0; i <= m_L; i++)
	{
		for (int j = 0; j <= m_S; j++)
		{
			addVertexToGraph({ i, j });
		}
	}
}

void DirGraph::addVertexToGraph(pair<int, int> vertex)
{
	if (m_AdjList.find(vertex) == m_AdjList.end())
	{
		m_AdjList[vertex] = list<pair<int, int>>();
	}
}

void DirGraph::addEdge(pair<int, int> u, pair<int, int> v)
{
	if (m_AdjList.find(u) != m_AdjList.end() && m_AdjList.find(v) != m_AdjList.end())
	{
		m_AdjList[u].push_back(v);
		m_AdjList[v].push_back(u);
	}
	else
	{
		cout << "Failed to add edge! One or both vertices do not exist in the graph." << endl;
	}
}

void DirGraph::addEdgeFillLargeJug()
{
}

void DirGraph::addEdgeFillSmallJug()
{
}

void DirGraph::addEdgeEmptyLargeJug()
{
}

void DirGraph::addEdgeEmptySmallJug()
{
}

void DirGraph::addEdgePourLargeJugToSmallJug()
{
}

void DirGraph::addEdgePourSmallJugToLargeJug()
{
}



list<pair<int, int>> DirGraph::getAdjList(pair<int, int> vertex)
{
	if (m_AdjList.find(vertex) != m_AdjList.end())
	{
		return m_AdjList[vertex];
	}
	else
	{
		cout << "Vertex not found!" << endl;
		return list<pair<int, int>>();
	}
}

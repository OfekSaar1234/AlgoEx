#include "DirGraph.h"

void DirGraph::MakeEmptyGraph(int numOfVertices)
{
	vertices.reserve(m_numVertices);
	addVerticesToGraph();
}

void DirGraph::FillGraphEdges()
{
	addEdgeFillLargeJug();
	addEdgeFillSmallJug();
	addEdgeEmptyLargeJug();
	addEdgeEmptySmallJug();
	addEdgePourLargeJugToSmallJug();
	addEdgePourSmallJugToLargeJug();
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
	Vertex v(vertex.first, vertex.second);
	vertices.push_back(v);
}

void DirGraph::addEdge(Vertex from, Vertex to)
{
	from.addNeighbor(to);
}

void DirGraph::addEdgeFillLargeJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount < m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount <= m_S; smallCurrAmount++)
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount;
			int destination = m_L * (m_S + 1) + smallCurrAmount;
			addEdge(vertices[current], vertices[destination]);
		}
	}
}

void DirGraph::addEdgeFillSmallJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount < m_S; smallCurrAmount++)
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount;
			int destination = largeCurrAmount * (m_S + 1) + m_S;
			addEdge(vertices[current], vertices[destination]);
		}
	}
}

void DirGraph::addEdgeEmptyLargeJug()
{
	for (int largeCurrAmount = 1; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount <= m_S; smallCurrAmount++)
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount;
			int destination = smallCurrAmount;
			addEdge(vertices[current], vertices[destination]);
		}
	}
}

void DirGraph::addEdgeEmptySmallJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 1; smallCurrAmount <= m_S; smallCurrAmount++)
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount;
			int destination = largeCurrAmount * (m_S + 1);
			addEdge(vertices[current], vertices[destination]);
		}
	}
}

void DirGraph::addEdgePourLargeJugToSmallJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount <= m_L; largeCurrAmount++) // rows
	{
		for (int smallCurrAmount = 0; smallCurrAmount < m_S; smallCurrAmount++) //columns
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount; // the row = i * (m_S + 1) //the col = j
			int pourAmount = min(largeCurrAmount, m_S - smallCurrAmount); // pour amount
			int destination = (largeCurrAmount - pourAmount) * (m_S + 1) + (smallCurrAmount + pourAmount); // (j + pourAmount)
			addEdge(vertices[current], vertices[destination]);
		}
	}
}

void DirGraph::addEdgePourSmallJugToLargeJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount < m_L; largeCurrAmount++) // rows
	{
		for (int smallCurrAmount = 0; smallCurrAmount <= m_S; smallCurrAmount++) //columns
		{
			int current = largeCurrAmount * (m_S + 1) + smallCurrAmount; // the row = i * (m_S + 1) //the col = j
			int pourAmount = min(m_L - largeCurrAmount, smallCurrAmount); // pour amount
			int destination = (largeCurrAmount + pourAmount) * (m_S + 1) + (smallCurrAmount - pourAmount); 
			addEdge(vertices[current], vertices[destination]);
		}
	}
}



list<Vertex> DirGraph::getAdjList(Vertex vertex)
{
	return vertex.getNeighbors();
}

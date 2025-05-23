#include "DirGraphImp1.h"

void DirGraphImp1::MakeEmptyGraph(int numOfVertices)
{
	m_AdjList.resize(m_numVertices);
	//addVerticesToGraph();
}

void DirGraphImp1::FillGraphEdges()
{
	addEdgeFillLargeJug();
	addEdgeFillSmallJug();
	addEdgeEmptyLargeJug();
	addEdgeEmptySmallJug();
	addEdgePourLargeJugToSmallJug();
	addEdgePourSmallJugToLargeJug();

	sortAdjList(); // sort the adjacency list neighbors Lexicographically for each vertex
}

void DirGraphImp1::sortAdjList()
{
	for (auto& adjList : m_AdjList)
	{    //// (1,4)->(2,3) -> (3,2) -> (4,1)
		adjList.sort([](const pair<pair<int, int>, EdgeType>& a, const pair<pair<int, int>, EdgeType>& b)
		{
			if (a.first.first < b.first.first) // Compare the `pair<int, int>` lexicographically
			{
				return true;
			}
			else if (b.first.first < a.first.first)
			{
				return false;
			}
			else // first are equal
			{
				return a.first.second < b.first.second;
			}
		});
	}
}

void DirGraphImp1::addEdge(pair<int, int> from, pair<int, int> to, EdgeType edgeType) // to add the string of the type of edge
{
	m_AdjList[Utils::getIndex(from, getS())].push_back(make_pair(to, edgeType)); // add the edge to the adj list of the vertex
}

// Fill large jug (Red)
void DirGraphImp1::addEdgeFillLargeJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount < m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount <= m_S; smallCurrAmount++)
		{   
			addEdge(make_pair(largeCurrAmount,smallCurrAmount), make_pair(m_L,smallCurrAmount), EdgeType::Red);
		}
	}
}

// Fill small jug (Green)
void DirGraphImp1::addEdgeFillSmallJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount < m_S; smallCurrAmount++)
		{
			addEdge(make_pair(largeCurrAmount, smallCurrAmount), make_pair(largeCurrAmount,m_S), EdgeType::Green);
		}
	}
}

// Empty large jug (Orange)
void DirGraphImp1::addEdgeEmptyLargeJug()
{
	for (int largeCurrAmount = 1; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 0; smallCurrAmount <= m_S; smallCurrAmount++)
		{
			addEdge(make_pair(largeCurrAmount, smallCurrAmount), make_pair(0, smallCurrAmount), EdgeType::Orange);
		}
	}
}

// Empty small jug (LightBlue)
void DirGraphImp1::addEdgeEmptySmallJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount <= m_L; largeCurrAmount++)
	{
		for (int smallCurrAmount = 1; smallCurrAmount <= m_S; smallCurrAmount++)
		{
			addEdge(make_pair(largeCurrAmount, smallCurrAmount), make_pair(largeCurrAmount, 0), EdgeType::LightBlue);
		}
	}
}

// Transfer from large jug to small jug (Purple)
void DirGraphImp1::addEdgePourLargeJugToSmallJug()
{
	for (int largeCurrAmount = 1; largeCurrAmount <= m_L; largeCurrAmount++) // rows
	{
		for (int smallCurrAmount = 0; smallCurrAmount < m_S; smallCurrAmount++) //columns
		{
			int pourAmount = min(largeCurrAmount, m_S - smallCurrAmount); // pour amount
			addEdge(make_pair(largeCurrAmount, smallCurrAmount), make_pair(largeCurrAmount - pourAmount,
				smallCurrAmount + pourAmount), EdgeType::Purple);
		}
	}
}

// Transfer from small jug to large jug (Blue)
void DirGraphImp1::addEdgePourSmallJugToLargeJug()
{
	for (int largeCurrAmount = 0; largeCurrAmount < m_L; largeCurrAmount++) // rows
	{
		for (int smallCurrAmount = 1; smallCurrAmount <= m_S; smallCurrAmount++) //columns
		{
			int pourAmount = min(m_L - largeCurrAmount, smallCurrAmount); // pour amount
			addEdge(make_pair(largeCurrAmount, smallCurrAmount), make_pair(largeCurrAmount + pourAmount,
				smallCurrAmount - pourAmount), EdgeType::Blue);
		}
	}
}

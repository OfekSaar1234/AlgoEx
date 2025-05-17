#pragma once

#include <unordered_map>
#include <queue>
#include "DirGraphImp2.h"
#include "EdgeType.h"
#include "Utils.h"

#define PARENTLESS -1 


using namespace std;

class BFSImp2
{
private:

    DirGraphImp2* m_Graph;
	int numOfMaxVertices;
	vector<pair<int, EdgeType>> m_Parents; // key(child), value(parent, edgeType)

public:

	BFSImp2(DirGraphImp2* graph) : m_Graph(graph), numOfMaxVertices((graph->getL() + 1)* (graph->getS() + 1)), m_Parents(numOfMaxVertices, { PARENTLESS, EdgeType::None }) {}

    void runSecondImplementation(int startVertex, int goalVertex)
    {
        queue<int> queue;
		vector<pair<pair<int, int>, EdgeType>> neighbors;
		int currentVertex;
		int smallJugSize = m_Graph->getS();

		queue.push(startVertex); // add start vertex to queue
		m_Graph->markVisited(startVertex); // add vertex to visited vertices

        while (!queue.empty())
        {
            currentVertex = queue.front();
            queue.pop();

            if (currentVertex == goalVertex)
                break;

			neighbors.clear();
			m_Graph->CalculateAdjList(neighbors, Utils::getVertex(currentVertex, smallJugSize));

            for (const auto& neighbor : neighbors)
            {
				int neighborVertex = Utils::getIndex(neighbor.first, smallJugSize);

                if(!m_Graph->vertexBeenVisited(neighborVertex)) // not visited vertex yet
                {
                    queue.push(neighborVertex); // push to queue
                    m_Graph->markVisited(neighborVertex); // add to visited vertices
					m_Parents[neighborVertex] = make_pair(currentVertex, neighbor.second); //add key(child), value{parent, edgeType}
                }
            }
        }
    }

	void printPath(int goalVertex)
	{
		if (m_Parents[goalVertex].first == PARENTLESS)
		{
			if(!m_Graph->vertexBeenVisited(goalVertex))
			{
				cout << "No solution." << endl;
				return;
			}
		}
		
		vector<EdgeType> operations;
		int numberOfOperations = 0;
		int currentVertex = goalVertex;

		while (m_Parents[currentVertex].first != PARENTLESS)// while not starting vertex
		{
			numberOfOperations++;
			operations.push_back(m_Parents[currentVertex].second);
			currentVertex = m_Parents[currentVertex].first;
		}

		Utils::printOperations(operations, numberOfOperations);
	}
};
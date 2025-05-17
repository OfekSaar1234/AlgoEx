#pragma once

#include <unordered_map>
#include <queue>
#include "DirGraphImp2.h"
#include "EdgeType.h"
#include "Utils.h"

using namespace std;

class BFSImp2
{
private:

    DirGraphImp2* m_Graph;
	unordered_map<int, pair<int, EdgeType>> m_Parents; // key(child), value(parent, edgeType)

public:

    BFSImp2(DirGraphImp2* graph) : m_Graph(graph) {}

    void runSecondImplementation(int startVertex, int goalVertex)
    {
        queue<int> queue;
		int currentVertex;

		queue.push(startVertex); // add start vertex to queue
		m_Graph->addVertexToGraph(startVertex); // add vertex to visited vertices

        while (!queue.empty())
        {
            currentVertex = queue.front();
            queue.pop();

            if (currentVertex == goalVertex)
                break;

            for (const auto& neighbor : m_Graph->CalculateAdjList(Utils::getVertex(currentVertex, m_Graph->getS())))
            {
				int neighborVertex = Utils::getIndex(neighbor.first, m_Graph->getS());

                if(!m_Graph->vertexBeenVisited(neighborVertex)) // not visited vertex yet
                {
                    queue.push(neighborVertex); // push to queue
                    m_Graph->addVertexToGraph(neighborVertex); // add to visited vertices
					m_Parents[neighborVertex] = make_pair(currentVertex, neighbor.second); //add key(child), value{parent, edgeType}
                }
            }
        }
    }

	void printPath(int goalVertex)
	{

		if (m_Parents.find(goalVertex) == m_Parents.end())
		{
			if(!m_Graph->vertexBeenVisited(goalVertex)) // only one incident in which the goal vertex is the starting vertex
			{
				cout << "No solution." << endl;
			}
			return;
		}
		
		vector<EdgeType> operations;
		int numberOfOperations = 0;
		int currentVertex = goalVertex;

		while (m_Parents.find(currentVertex) != m_Parents.end())// while not starting vertex
		{
			numberOfOperations++;
			operations.push_back(m_Parents[currentVertex].second);
			currentVertex = m_Parents[currentVertex].first;
		}

		if (operations.size() != 0)
		{
			reverse(operations.begin(), operations.end());
		}

		Utils::printOperations(operations, numberOfOperations);
	}
};
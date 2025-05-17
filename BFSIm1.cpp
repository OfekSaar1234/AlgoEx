#include "BFSIm1.h"

void BFSIm1::runFirstImplementation(DirGraphImp1& graph, pair<int, int> startVertex)
{
    queue<pair<int, int>> queue;

    // Initialize BFS
    int startIndex = Utils::getIndex(startVertex, graph.getS());
    queue.push(startVertex);
    d[startIndex] = 0;

    while (!queue.empty())
    {
        pair<int, int> currentVertex = queue.front();
        queue.pop();

        int currentIndex = Utils::getIndex(currentVertex, graph.getS());

        // Explore neighbors
        for (const auto& neighbor : graph.getAdjList(currentVertex))
        {
            pair<int, int> neighborVertex = neighbor.first; // neighbor = pair<pair<int, int>, edgeType>
            int neighborIndex = Utils::getIndex(neighborVertex, graph.getS());

            if (d[neighborIndex] == INFINITY)
            {
                d[neighborIndex] = d[currentIndex] + 1; // Update distance
                p[neighborIndex] = currentIndex;        // Set parent
                queue.push(neighborVertex);             // Enqueue neighbor
            }
        }
    }
}

void BFSIm1::printPath(const pair<int, int>& goalVertex, DirGraphImp1& graph) const
{
    if (!isReachable(goalVertex, graph))
    {
        cout << "No solution." << endl;
        return;
    }

    int numOfOperations = d[Utils::getIndex(goalVertex, graph.getS())];

    vector<EdgeType> operations;
    operations.reserve(numOfOperations);

    int currentIndex = Utils::getIndex(goalVertex, graph.getS());
    pair<int, int> parentVertex, currentVertex;
    while (p[currentIndex] != PARENTLESS) // =! root
    {
        parentVertex = Utils::getVertex(p[currentIndex], graph.getS());
        currentVertex = Utils::getVertex(currentIndex, graph.getS());
        operations.push_back(graph.getEdge(parentVertex, currentVertex));
        currentIndex = p[currentIndex];
    }

    if(operations.size() != 0)
    {
		reverse(operations.begin(), operations.end());
    }

	Utils::printOperations(operations, numOfOperations);
}
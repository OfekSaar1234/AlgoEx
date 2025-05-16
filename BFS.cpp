#include "BFS.h"

void BFS::runFirstImplementation(DirGraph& graph, pair<int, int> startVertex)
{
    queue<pair<int, int>> queue;

    // Initialize BFS
    int startIndex = graph.getIndex(startVertex);
    queue.push(startVertex);
    d[startIndex] = 0;

    while (!queue.empty())
    {
        pair<int, int> currentVertex = queue.front();
        queue.pop();

        int currentIndex = graph.getIndex(currentVertex);

        // Explore neighbors
        for (const auto& neighbor : graph.getAdjList(currentVertex))
        {
            pair<int, int> neighborVertex = neighbor.first; // neighbor = pair<pair<int, int>, edgeType>
            int neighborIndex = graph.getIndex(neighborVertex);

            if (d[neighborIndex] == INFINITY)
            {
                d[neighborIndex] = d[currentIndex] + 1; // Update distance
                p[neighborIndex] = currentIndex;        // Set parent
                queue.push(neighborVertex);             // Enqueue neighbor
            }
        }
    }
}

void BFS::printPath(const pair<int, int>& goalVertex, DirGraph& graph) const
{
    if (!isReachable(goalVertex, graph))
    {
        cout << "No solution." << endl;
        return;
    }

    int numOfOperations = d[graph.getIndex(goalVertex)];

    vector<EdgeType> operations;
    operations.reserve(numOfOperations);

    int currentIndex = graph.getIndex(goalVertex);
    pair<int, int> parentVertex, currentVertex;
    while (p[currentIndex] != PARENTLESS) // =! root
    {
        parentVertex = graph.getVertex(p[currentIndex]);
        currentVertex = graph.getVertex(currentIndex);
        operations.push_back(graph.getEdge(parentVertex, currentVertex));
        currentIndex = p[currentIndex];
    }

    if(operations.size() != 0)
    {
		reverse(operations.begin(), operations.end());
		printOperations(operations, numOfOperations);
    }
}

void BFS::printEdgeType(EdgeType edgeType) const
{
    switch (edgeType)
    {
    case EdgeType::Green:
        cout << "Fill small jug" << endl;
        break;
    case EdgeType::Red:
        cout << "Fill large jug" << endl;
        break;
    case EdgeType::Orange:
        cout << "Empty large jug" << endl;
        break;
    case EdgeType::LightBlue:
        cout << "Empty small jug" << endl;
        break;
    case EdgeType::Blue:
        cout << "Transfer from small jug to large jug" << endl;
        break;
    case EdgeType::Purple:
        cout << "Transfer from large jug to small jug" << endl;
        break;
    default:
        cout << "Unknown EdgeType" << endl;
        break;
    }
}

void BFS::printOperations(const vector<EdgeType>& operations, int numOfOperations) const
{
    cout << "Number of operations: " << numOfOperations << endl;
	cout << "Operations:" << endl;
    for (int i = 0; i < numOfOperations; i++)
    {
        cout << i+1 << ". ";
        printEdgeType(operations[i]);
    }
}

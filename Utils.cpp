#include "Utils.h"

void Utils::printOperations(const vector<EdgeType>& operations, int numOfOperations)
{
    cout << "Number of operations: " << numOfOperations << endl;
    cout << "Operations:" << endl;
    for (int i = numOfOperations - 1; i >= 0; i--)
    {
        cout << numOfOperations - i << ". ";
        printEdgeType(operations[i]);
    }
}

void Utils::printEdgeType(EdgeType edgeType)
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

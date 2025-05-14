#pragma once
#include <list>
#include <utility> // For pair

using namespace std; 

class Vertex {
private:

    pair<int, int> m_Data; // The state of the vertex (L, S)
    list<Vertex> m_AdjList; // List of neighbors


public:

    Vertex(int largeJug, int smallJug) : m_Data({ largeJug, smallJug }) {}

    pair<int, int> getData() const { return m_Data; }

    void addNeighbor(const Vertex& neighbor) { m_AdjList.push_back(neighbor); }

    list<Vertex> getNeighbors() const { return m_AdjList; }

};
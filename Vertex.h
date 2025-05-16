//#pragma once
//#include <list>
//#include <utility> // For pair
//#include <string>
//#include "EdgeType.h"
//
//using namespace std; 
//
//class Vertex {
//private:
//
//    pair<int, int> m_Data; // The state of the vertex (L, S)
//    //list<pair<Vertex, EdgeType>> m_AdjList; // List of neighbors with edge types
//
//
//public:
//
//    Vertex(int largeJug, int smallJug) : m_Data({ largeJug, smallJug }) {}
//
//    pair<int, int> getData() const { return m_Data; }
//
//    //void addNeighbor(const Vertex& neighbor, EdgeType edgeType) { m_AdjList.push_back({ neighbor, edgeType }); }
//
//    //list<pair<Vertex, EdgeType>> getNeighbors() const { return m_AdjList; }
//
//};
#include "DirGraphImp2.h"

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborFillLargeJug (const pair<int, int>& vertex) const
{

	return make_pair(make_pair(m_L, vertex.second), EdgeType::Red);
}

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborFillSmallJug(const pair<int, int>& vertex) const
{
	return make_pair(make_pair(vertex.first, m_S), EdgeType::Green);
}

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborEmptyLargeJug(const pair<int, int>& vertex) const
{
	return make_pair(make_pair(0, vertex.second), EdgeType::Orange);
}

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborEmptySmallJug(const pair<int, int>& vertex) const
{
	return  make_pair(make_pair(vertex.first, 0), EdgeType::LightBlue);
}

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborPourLargeJugToSmallJug(const pair<int, int>& vertex) const
{
	int pourAmount = min(vertex.first, m_S - vertex.second);
	return make_pair(make_pair(vertex.first - pourAmount, vertex.second + pourAmount), EdgeType::Purple);
}

pair<pair<int, int>, EdgeType> DirGraphImp2::getNeighborPourSmallJugToLargeJug(const pair<int, int>& vertex) const
{
	int pourAmount = min(m_L - vertex.first, vertex.second);
	return make_pair(make_pair(vertex.first + pourAmount, vertex.second - pourAmount), EdgeType::Blue);
}

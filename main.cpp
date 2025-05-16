#include "DirGraph.h"
#include "FirstAlgorithm.h"
#include "BFS.h"
#include <chrono>

#include <iostream>

int main() 
{

    auto start = chrono::high_resolution_clock::now();

    DirGraph graph(6, 4);
    BFS bfs(graph);

    bfs.runFirstImplementation(graph, { 0, 0 });
    bfs.printPath({ 5, 0 }, graph);

    auto end = chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
    return 0;

}



/// creat graph with all vertiecesa and edges
/// sort adj of all v's
/// creat members d[] and p[] 
/// run BFS starting from [0,0]
/// from destination [{w,0}] go to parents and run backwards untill {0,0}
/// append to start of a new list each eadge type and print it in switch case according to type  
/// 
#include "DirGraphImp1.h"
#include "DirGraphImp2.h"
#include "FirstAlgorithm.h"
#include "BFSIm1.h"
#include "BFSImp2.h"
#include <chrono>

#include <iostream>

int main() 
{
    
    // before activating solutions, check validity of input
    // int L, S, W, implementation, runTime;

    // cin >> L >> S >> W >> implementation >> runTime;

    // auto start = chrono::high_resolution_clock::now();

    // DirGraphImp1 graph(6, 4);
    // BFSIm1 bfs(graph);

    // bfs.runFirstImplementation(graph, { 0, 0 });
    // bfs.printPath({ 5, 0 }, graph);

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
    // return 0;

    DirGraphImp2 graph(4, 3);
    BFSImp2 bfs(&graph);

    bfs.runSecondImplementation(0, Utils::getIndex({2, 0}, graph.getS()));
    bfs.printPath(Utils::getIndex({ 2, 0 }, graph.getS()));
}







//to do
//
// fix BFSimp1
// change bfs function to RUN
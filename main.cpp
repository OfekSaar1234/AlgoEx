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

   /* auto start = chrono::high_resolution_clock::now();

    DirGraphImp1 graph(4, 3);
    BFSIm1 bfs(graph);

    bfs.runFirstImplementation(graph, { 0, 0 });
    bfs.printPath({ 2, 0 }, graph);

    auto end = chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
    return 0;*/

	// auto start = chrono::high_resolution_clock::now();

 //    DirGraphImp2 graph(4, 3);
 //    BFSImp2 bfs(&graph);

 //    bfs.runSecondImplementation(0, Utils::getIndex({2, 0}, graph.getS()));
 //    bfs.printPath(Utils::getIndex({ 2, 0 }, graph.getS()));

 //    auto end = chrono::high_resolution_clock::now();
 //    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
 //    std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
 //    return 0;





    // const int repetitions = 1000; // Number of times to repeat
    // std::vector<long long> times; // Store durations

    // for (int i = 0; i < repetitions; ++i)
    // {
    //     auto start = std::chrono::high_resolution_clock::now();

    //     DirGraphImp1 graph(4, 3);
    //     BFSIm1 bfs(graph);

    //     bfs.runFirstImplementation(graph, { 0, 0 });
    //     bfs.printPath({ 0, 0 }, graph);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     times.push_back(duration.count());
    // }

    // // Calculate average and standard deviation
    // long long sum = 0;
    // for (auto t : times) sum += t;
    // double avg = static_cast<double>(sum) / repetitions;

    // double sq_sum = 0;
    // for (auto t : times) sq_sum += (t - avg) * (t - avg);
    // double stddev = std::sqrt(sq_sum / repetitions);

    // std::cout << "Average time: " << avg << " microseconds." << std::endl;
    // std::cout << "Standard deviation: " << stddev << " microseconds." << std::endl;

    // return 0;








    // const int repetitions = 1000;
    // std::vector<long long> times;

    // for (int i = 0; i < repetitions; ++i)
    // {
    //    auto start = std::chrono::high_resolution_clock::now();

    //    DirGraphImp2 graph(4, 3);
    //    BFSImp2 bfs(&graph);

    //    bfs.runSecondImplementation(0, Utils::getIndex({ 0, 0 }, graph.getS()));
    //    bfs.printPath(Utils::getIndex({ 0, 0 }, graph.getS()));

    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //    times.push_back(duration.count());
    // }

    // // Calculate average and standard deviation
    // long long sum = 0;
    // for (auto t : times) sum += t;
    // double avg = static_cast<double>(sum) / repetitions;

    // double sq_sum = 0;
    // for (auto t : times) sq_sum += (t - avg) * (t - avg);
    // double stddev = std::sqrt(sq_sum / repetitions);

    // std::cout << "Average time: " << avg << " microseconds." << std::endl;
    // std::cout << "Standard deviation: " << stddev << " microseconds." << std::endl;

    // return 0;

}







//to do
//
// fix BFSimp1
// change bfs function to RUN
/**
 * @file
 * @brief [Kruskals Minimum Spanning
 * Tree](https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm)
 * implementation
 *
 * @details
 * _Quoted from
 * [Simplilearn](https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm)._
 *
 * Kruskal’s algorithm is the concept that is introduced in the graph theory of
 * discrete mathematics. It is used to discover the shortest path between two
 * points in a connected weighted graph. This algorithm converts a given graph
 * into the forest, considering each node as a separate tree. These trees can
 * only link to each other if the edge connecting them has a low value and
 * doesn’t generate a cycle in MST structure.
 *
 * @author [coleman2246](https://github.com/coleman2246)
 */

#include <array>    
#include <iostream>  
#include <limits>   
#include <cfloat>  

/**
 * @namespace
 * @brief Greedy Algorithms
 */
namespace greedy_algorithms {
/**
 * @brief Finds the minimum edge of the given graph.
 * @param infinity Defines the infinity of the graph
 * @param graph The graph that will be used to find the edge
 * @returns void
 */
template <typename T, std::size_t N, std::size_t M>
void findMinimumEdge(const T &infinity,
                     const std::array<std::array<T, N>, M> &graph) {
    if (N != M) {
        std::cout << "\nWrong input passed. Provided array has dimensions " << N
                  << "x" << M << ". Please provide a square matrix.\n";
        return;
    }
    for (int i = 0; i < graph.size(); i++) {
        T min = infinity;
        int minIndex = -1;
        for (int j = 0; j < graph.size(); j++) {
            if (i != j && graph[i][j] != 0 && graph[i][j] < min) {
                min = graph[i][j];
                minIndex = j;
            }
        }
        if (minIndex != -1) {  // If we found a valid connection
            std::cout << i << "  -  " << minIndex << "\t" << graph[i][minIndex] << std::endl;
        } else {
            std::cout << i << " has no valid connections." << std::endl;
        }
    }
}
}  // namespace greedy_algorithms

/**
 * @brief Self-test implementations
 * @returns void
 */
static void selfTest() {
    // Test 1: Graph with integer values
    std::cout << "Test case 1:\n";
    std::array<std::array<int, 4>,4> graph1{
        0,          2,    5,    INT_MAX,
        2,          0,    3,    4,
        5,          3,    0,    6,
        INT_MAX,    4,    6,    0};
    greedy_algorithms::findMinimumEdge(INT_MAX, graph1);

    // Test 2: Graph with float values
    std:: cout << "Test case 2: \n";
    std::array<std::array<float, 3>,3> graph2{{
        {0.0f,    2.3f,    FLT_MAX},
        {2.3f,    0.0f,    1.0f},
        {FLT_MAX, 1.0f,    0.0f}
        }};
    greedy_algorithms::findMinimumEdge(FLT_MAX, graph2);

    // Test 3: Graph with negative weights
    std:: cout << "Test case 3: \n";
    std::array<std::array<int, 4>,4> graph3{
        0,   2,   3,
        2,   0,   -4,
        3,  -4,   0};
    greedy_algorithms::findMinimumEdge(INT_MAX, graph3);
    
    //Test4: Non-connected graphs
    std::cout << "Test case 4:\n";
    std::array<std::array<int, 4>,4> graph4{
        0,          INT_MAX,    5,         2,
        INT_MAX,    0,          3,         4,
        5,          3,          0,         INT_MAX,
        2,          4,          INT_MAX,    0};
    greedy_algorithms::findMinimumEdge(INT_MAX, graph4);

    // Test 5: Fail with Directed graph: 
    std::cout << "Test case 5:\n";
    std::array<std::array<int, 4>,4> graph5{
        0,          2,          5,          INT_MAX,
        INT_MAX,    0,          3,          4,
        INT_MAX,    INT_MAX,    0,          5,
        INT_MAX,    INT_MAX,    INT_MAX,    0};
    greedy_algorithms::findMinimumEdge(INT_MAX, graph5);

    // Test 6: Fail with Unmatcheed dimensional graph: 
    std::cout << "Test case 6:\n";
    std::array<std::array<int, 4>,3> graph6{
        0,4,5,6,
        4,0,3,2,
        5,3,2,4};
    greedy_algorithms::findMinimumEdge(INT_MAX, graph6);

    std::cout << "Done testing!\n";
}

int main() {
    selfTest();  // run Self-test implementation
    return 0;
}


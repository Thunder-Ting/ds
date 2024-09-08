//
// Created by 86178 on 2024-09-08.
//

#include "AdjMatrix/AdjMatrix.h"

int main() {
    Graph gp(6);
    gp.addEdge(1, 2, 6);
    gp.addEdge(1, 4, 5);
    gp.addEdge(1, 3, 1);
    gp.addEdge(2, 5, 3);
    gp.addEdge(2, 3, 5);
    gp.addEdge(3, 5, 6);
    gp.addEdge(3, 6, 4);
    gp.addEdge(3, 4, 5);
    gp.addEdge(4, 6, 2);
    gp.addEdge(5, 6, 6);
    std::cout << "Graph adjacency matrix:\n";
    gp.printGraph();

//    std::cout << "\nMinimum Spanning Tree:\n";
    gp.primMST();
}
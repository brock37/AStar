#include <iostream>
#include "graph.h"

int main(int argc, char **argv) {
    std::cout << "Init du graph" << std::endl;
    Graph graph(5,5);
    graph.initGraph();
    graph.afficherGraph();
    
    return 0;
}

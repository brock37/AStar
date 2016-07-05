#include <iostream>
#include "graph.h"
#include "pathfinder.h"
#include "node.h"

int main(int argc, char **argv) {
    std::cout << "Init du graph" << std::endl;
    
    Graph graph(5,5);
    graph.initGraph();
    graph.afficherGraph();
    
    std::cout << graph.findNode(1,1)->getChar() << "," << graph.findNode(1,1) << std::endl;
   
    return 0;
}

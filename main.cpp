#include <iostream>
#include "graph.h"
#include "pathfinder.h"
#include "node.h"

int main(int argc, char **argv) {
  std::pair<int, int > n(1,1);
    std::cout << "Init du graph" << std::endl;
    
    Graph graph(5,5);
    graph.initGraph();
    graph.afficherGraph();
    
    std::cout << graph.findNode(1,1).getChar() << ",";
    std::cout << " Pos: " << graph.getNodePosition(1,1).first << "," << graph.getNodePosition(1,1).second << std::endl;
    
    graph.afficherGraph();
    graph.findNode(1,1).setChar('X');
    graph.afficherGraph();
   graph.findNode(2,1).setChar('X');
   graph.afficherGraph();
    return 0;
}

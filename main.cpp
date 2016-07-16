#include <iostream>
#include "graph.h"
#include "pathfinder.h"
#include "node.h"

int main(int argc, char **argv) {
    std::pair<int, int > depart(1,1);
    std::pair<int, int > arrive(2,2);
    std::cout << "Init du graph" << std::endl;    
    
    Graph graph(5,5);
    graph.initGraph();
    graph.afficherGraph();
    
    PathFinder path(&graph, depart, arrive);
    path.addAdjacentNodeListeOuverte( depart);
    /*path.addListeFermee(std::pair<int, int >(2,2));
    path.addListeFermee(std::pair<int, int >(3,2));
    std::cout<< path.inListeFermee(std::pair<int, int >(2,2)) << "," << path.inListeFermee(std::pair<int, int >(2,3)) << std::endl;
    
    std::cout << graph.findNode(1,1).getChar() << ",";
    std::cout << " Pos: " << graph.getNodePosition(1,1).first << "," << graph.getNodePosition(1,1).second << std::endl;
  /*  
    graph.afficherGraph();
    graph.findNode(1,1).setChar('X');
    graph.afficherGraph();
    
    std::cout << std::endl;
   graph.findNode(2,1).setChar('X');
   graph.afficherGraph();
   
  */ 
   
    return 0;
}

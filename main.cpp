#include <iostream>
#include "graph.h"
#include "pathfinder.h"
#include "node.h"

int main(int argc, char **argv) {
    std::pair<int, int > depart(0,0);
    std::pair<int, int > arrive(0,2);
    std::cout << "Init du graph" << std::endl;    
    
    Graph graph(5,5);
    graph.initGraph();
    
    PathFinder path(&graph, depart, arrive);
    
    graph.findNode(1,1).setChar('X');
    graph.findNode(1,1).setwalkable(false);
    graph.findNode(2,1).setChar('X');
    graph.findNode(2,1).setwalkable(false);
    graph.findNode(3,1).setChar('X');
    graph.findNode(3,1).setwalkable(false);
    graph.findNode(0,1).setChar('X');
    graph.findNode(0,1).setwalkable(false);
    

    graph.afficherGraph();
    path.findPath();
    /*path.addListeFermee(std::pair<int, int >(3,2));
    std::cout<< path.inListeFermee(std::pair<int, int >(2,2)) << "," << path.inListeFermee(std::pair<int, int >(2,3)) << std::endl;
    
    std::cout << graph.findNode(1,1).getChar() << ",";
    std::cout << " Pos: " << graph.getNodePosition(1,1).first << "," << graph.getNodePosition(1,1).second << std::endl;
  */  

   
   
    return 0;
}

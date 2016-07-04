#include <iostream>
#include "graph.h"
#include "pathfinder.h"
#include "node.h"

int main(int argc, char **argv) {
    std::cout << "Init du graph" << std::endl;
    
    Graph graph(5,5);
    graph.initGraph();
    graph.afficherGraph();
    
    PathFinder pathfinder(&graph, graph.findNode(0,0), graph.findNode(4,4));
    std::vector<Node*> chemin =pathfinder.findPath();
    //std::cout << pathfinder.distanceNoeud(graph.findNode(0,0), graph.findNode(4,4)) << std::endl;;
    return 0;
}

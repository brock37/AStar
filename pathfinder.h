#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <vector>
#include <algorithm>
#include <cmath> //sqrt
#include <map> //map
#include<utility> //pair
#include <list>
#include <iostream> //cout
#include "node.h"
#include "graph.h"

#define NODE_DISTANCE_VALUE 100

class PathFinder
{
public:
PathFinder();
PathFinder(Graph* graph, std::pair<int, int> depart, std::pair<int, int> arrive);
PathFinder(const PathFinder& other);
~PathFinder();

void addListeOuverte( std::pair<int, int> node);// a revoir pour verifier les case adjacentes dans la fonction
void addListeFermee(std::pair<int, int> node);//
void addAdjacentNodeListeOuverte( std::pair<int, int> centerNode);

void removeListeOuverte(std::pair<int, int> node);//

bool inListeFermee(std::pair<int, int> node);//
bool inListeOuverte(std::pair<int, int> node);//

void updateListeOuverte(std::pair<int, int> node, Node tmp_node);//
std::pair<int, int> getBestNodeListeOuverte();//
float distanceNoeud( std::pair<int, int> nodeDepart,  std::pair<int, int> nodeArrive);//
float distanceNoeud(int x1, int y1, int x2, int y2);

std::list< std::pair<int, int> > findPath();
std::list< std::pair<int, int> > retouverChemin();

void listerNode(std::list< std::pair<int, int> > liste);

void setStartNode(std::pair<int, int> depart){m_nodeDepart= depart;};
void setEndNode(std::pair<int, int> arrive){m_nodeArrive= arrive;};
void setGraph( Graph* graph){m_graph= graph;};

private:
  std::map< std::pair<int, int>, Node> m_listeOuverte;
  std::map< std::pair<int, int>, Node> m_listeFermee;
  std::pair<int, int> m_nodeDepart;
  std::pair<int, int> m_nodeArrive;
  Graph* m_graph;

};

#endif // PATHFINDER_H

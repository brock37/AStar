#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "node.h"
#include "graph.h"

#define NODE_DISTANCE_VALUE 100

class PathFinder
{
public:
PathFinder(Graph* graph, Node* depart, Node* arrive);
PathFinder(const PathFinder& other);
~PathFinder();

void addListeOuverte( Node* centerNode);// a revoir pour verifier les case adjacentes dans la fonction
void addListeFremee(Node* node);//

void removeListeOuverte(Node* node);//
void removeListeFermee(Node* node);//

bool inListeFermee( Node* node);//
bool inListeOuverte(Node* node);//

void updateListeOuverte(Node* node, Node* tmp);//
Node* getBestNodeListeOuverte();//
float distanceNoeud( Node* nodeDepart,  Node* nodeArrive);//

std::vector<Node*> findPath(); 


private:
  std::vector<Node*> m_listeOuverte;
  std::vector<Node*> m_listeFermee;
  Node* m_nodeDepart;
  Node* m_nodeArrive;
  Graph* m_graph;
  
};

#endif // PATHFINDER_H

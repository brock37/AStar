#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "node.h"

class Graph
{
public:
Graph(int hauteur, int largeur);
Graph(const Graph& other);
~Graph();
void initGraph();
void afficherGraph();

int getNombreLigne(){ return m_nombreLigne;};
int getNombreColonne(){ return m_nombreColonne;};
Node* findNode(int x, int j);

private:
  //std::vector<Node*> m_graph;
  std::map< std::pair<int, int>, Node*> m_graph;
  int m_nombreLigne;
  int m_nombreColonne;
};

#endif // GRAPH_H

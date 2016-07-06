#include "pathfinder.h"

PathFinder::PathFinder(Graph* graph, std::pair<int, int> depart, std::pair<int, int> arrive)
{
  m_graph= graph;
  m_nodeDepart= depart;
  m_nodeArrive= arrive;

}

PathFinder::PathFinder(const PathFinder& other)
{
  m_graph= other.m_graph;
  m_nodeDepart= other.m_nodeDepart;
  m_nodeArrive= other.m_nodeArrive;
}

PathFinder::~PathFinder()
{

}

std::map< std::pair<int, int>, Node*> PathFinder::findPath()
{
  /*
   *On commence par le noeud de départ, c'est le noeud courant
   *On regarde tous ses noeuds voisins
   *si un noeud voisin est un obstacle, on l'oublie
   *si un noeud voisin est déjà dans la liste fermée, on l'oublie
   *si un noeud voisin est déjà dans la liste ouverte, on met à jour la liste ouverte si le noeud dans la liste ouverte a une moins bonne qualité (et on n'oublie pas de mettre à jour son parent)
   *sinon, on ajoute le noeud voisin dans la liste ouverte avec comme parent le noeud courant
   *On cherche le meilleur noeud de toute la liste ouverte. Si la liste ouverte est vide, il n'y a pas de solution, fin de l'algorithme
   *On le met dans la liste fermée et on le retire de la liste ouverte
   *On réitère avec ce noeud comme noeud courant jusqu'à ce que le noeud courant soit le noeud de destination.
   */

}

void PathFinder::addAdjacentNodeListeOuverte(std::pair<int, int> centerNode)
{
  
}

void PathFinder::retouverChemin()
{

}

void PathFinder::removeListeOuverte(std::pair<int, int> node)
{
  if(m_listeOuverte.erase( node) == 0)
  {
    std::cerr << "Erreur, le noeud n'apparait pas dans la liste ouverte, impossible à supprimer" << std::endl;
  }
}



void PathFinder::addListeOuverte(std::pair<int, int> node)
{

}

void PathFinder::addListeFremee(std::pair<int, int>& node)
{
  
}

bool PathFinder::inListeOuverte(std::pair<int, int> node)
{
  
}

bool PathFinder::inListeFermee(std::pair<int, int> node)
{
  
}

void PathFinder::updateListeOuverte(std::pair<int, int> node, std::pair<int, int> tmp)
{
  
}

float PathFinder::distanceNoeud(std::pair<int, int> nodeDepart, std::pair<int, int> nodeArrive)
{
  int x1= nodeDepart.first;
  int y1= nodeDepart.second;
  int x2= nodeArrive.first;
  int y2= nodeArrive.second;
   /* distance euclidienne */
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

 
    /* carré de la distance euclidienne pour int */
    /* return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); */
}


std::pair<int, int> PathFinder::getBestNodeListeOuverte()
{
  
}

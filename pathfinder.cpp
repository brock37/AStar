#include "pathfinder.h"

PathFinder::PathFinder(Graph* graph, Node* depart, Node* arrive)
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

std::vector< Node* > PathFinder::findPath()
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

void PathFinder::addAdjacentNodeListeOuverte(Node* centerNode)
{
  
}

void PathFinder::retouverChemin()
{

}

void PathFinder::removeListeOuverte(Node* node)
{
}

void PathFinder::removeListeFermee(Node* node)
{

}


void PathFinder::addListeOuverte(Node* node)
{

}

void PathFinder::addListeFremee(Node* node)
{
  
}

bool PathFinder::inListeOuverte(Node* node)
{
  
}

bool PathFinder::inListeFermee(Node* node)
{
  
}

void PathFinder::updateListeOuverte(Node* node, Node* tmp)
{
  
}

float PathFinder::distanceNoeud(Node* nodeDepart, Node* nodeArrive)
{
  int x1= nodeDepart->getPosition().first;
  int y1= nodeDepart->getPosition().second;
  int x2= nodeArrive->getPosition().first;
  int y2= nodeArrive->getPosition().second;
   /* distance euclidienne */
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

 
    /* carré de la distance euclidienne pour int */


    /* carré de la distance euclidienne */

    /* return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); */
}


Node* PathFinder::getBestNodeListeOuverte()
{
  
}






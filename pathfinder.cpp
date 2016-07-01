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
  Node* current= m_nodeDepart;

  addListeFremee( current);
  addListeOuverte( current);
}


void PathFinder::removeListeOuverte(Node* node)
{
  std::vector<Node*>::iterator it = std::find( m_listeOuverte.begin(), m_listeOuverte.end(), node);
  m_listeOuverte.erase( it);
}

void PathFinder::removeListeFermee(Node* node)
{
    std::vector<Node*>::iterator it = std::find( m_listeFermee.begin(), m_listeFermee.end(), node);
    m_listeFermee.erase( it);
}

void PathFinder::addListeOuverte(Node* centerNode)
{
  std::pair<int, int> tmpPos= centerNode->getPosition();
  int x= tmpPos.first;
  int y= tmpPos.second;
  /*Pour chaque node en x adjacents*/
  for(int i= x-1; i <= x+1; i++);
    //Si en dehors de la map on arrete
  /*Pour chaque node en y adjacents*/
}


void PathFinder::addListeFremee(Node* node)
{
  m_listeFermee.push_back( node);
  removeListeOuverte( node);
}

bool PathFinder::inListeOuverte(Node* node)
{
  std::vector<Node*>::iterator it = std::find( m_listeOuverte.begin(), m_listeOuverte.end(), node);
  if( it == m_listeOuverte.end())
    return false;

  return true;

}

bool PathFinder::inListeFermee(Node* node)
{
  std::vector<Node*>::iterator it = std::find( m_listeFermee.begin(), m_listeFermee.end(), node);
  if( it == m_listeFermee.end())
    return false;

  return true;

}

void PathFinder::updateListeOuverte(Node* node, Node* tmp)
{
  std::vector<Node*>::iterator it = std::find( m_listeFermee.begin(), m_listeFermee.end(), node);
  if((*it)->getF() < tmp->getF())
      (*it)= tmp;

}

float PathFinder::distanceNoeud(Node* nodeDepart, Node* nodeArrive)
{
  int x1= nodeDepart->getPosition().first;
  int y1= nodeDepart->getPosition().second;
  int x2= nodeArrive->getPosition().first;
  int y2= nodeArrive->getPosition().second;
   /* distance euclidienne */
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    /* carré de la distance euclidienne */
    /* return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); */
}


Node* PathFinder::getBestNodeListeOuverte()
{
  Node* tmp= 0;
  std::vector<Node*>::iterator it= m_listeOuverte.begin();

  for(it = m_listeOuverte.begin(); it!= m_listeOuverte.end(); it++)
  {
    if(tmp->getF() < (*it)->getF())
      tmp = (*it);
  }

  return tmp;

}






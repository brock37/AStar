#include "pathfinder.h"

PathFinder::PathFinder(Graph* graph, Node* depart, Node* arrive)
{
  m_graph= graph;
  m_nodeDepart= depart;
  m_nodeArrive= arrive;
  m_listeFermee.reserve(25);
  m_listeOuverte.reserve(25);
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
  std::cout << "Depart:  " << m_nodeDepart->getChar() << " Arrive " << m_nodeArrive->getChar() << std::endl;
  std::vector<Node*> road;
  Node* current= m_nodeDepart;
<<<<<<< HEAD
=======

  addListeFremee( current);
>>>>>>> 3664475d9867f64fe503bf4ef81f17cc7f81de48
  addListeOuverte( current);
  addListeFremee( current);
  //removeListeOuverte(current);
  
  addAdjacentNodeListeOuverte( current);
  
  while( !m_listeOuverte.empty() && ( current != m_nodeArrive ))
  {
    std::cout << "Recherche de la meilleur node " << std::endl;
    current= getBestNodeListeOuverte();
    std::cout << "Node courant " << current->getChar() << ", " << current << std::endl;
    addListeFremee(current);
    //removeListeOuverte(current);
    addAdjacentNodeListeOuverte( current);
    
  }
  
  if(current == m_nodeArrive)
  {
    std::cout << "Chemin trouve" << std::endl;
  }
  else
  {
     std::cout << "Chemin NON trouve" << std::endl;
  }
  
  
  
  return road;
}

void PathFinder::addAdjacentNodeListeOuverte(Node* centerNode)
{
  Node tmpNode(0,0,'a');
  std::pair<int, int> tmpPos= centerNode->getPosition();
  int x= tmpPos.first;
  int y= tmpPos.second;
  /*Pour chaque node en x adjacents*/
  for(int i= x-1; i <= x+1; i++)
  {
    //Si en dehors du graph on arrete
    if( i < 0  || i >= m_graph->getNombreLigne())
      continue;
    
     for(int j= y-1; j <= y+1; j++)
     {
       //Si en dehors du graph on arrete
      if( j < 0  || j >= m_graph->getNombreLigne())
	continue;
	//Si case courante on arrete
      if( i == x && j == y)
	continue;
      //Si c'est un obstacle on arrete
      if( m_graph->findNode(i,j)->getWalkable() == false)
	continue;
      
      Node* nodeAdjacente= m_graph->findNode(i,j);
      
      if( !inListeFermee( nodeAdjacente))
      {
	float coutG= nodeAdjacente->getG() + distanceNoeud( m_nodeDepart, nodeAdjacente);
	float coutH= distanceNoeud( nodeAdjacente, m_nodeArrive);
	float coutF= coutG + coutH;
	nodeAdjacente->setF( coutF);
	nodeAdjacente->setG(coutG);
	nodeAdjacente->setH(coutH);
	/*tmpNode.setPosition(std::pair<int,int>(i,j));
	tmpNode.setChar( nodeAdjacente->getChar());
	tmpNode.setwalkable( nodeAdjacente->getWalkable());
	tmpNode.setPosition( nodeAdjacente->getPosition());
	//Calcul du cout G 
	tmpNode.setG( m_nodeDepart->getG() + distanceNoeud( m_nodeDepart, nodeAdjacente));
	//Calcul du cout H
	tmpNode.setH(distanceNoeud( nodeAdjacente, m_nodeArrive) + m_nodeArrive->getH());
	//Calcul du coup F= G+H
	tmpNode.setF( tmpNode.getG() + tmpNode.getH());
	tmpNode.setparent( centerNode);*/
	if(inListeOuverte( nodeAdjacente))
	{
	  //Si deja present dans la liste ouverte on le met a jour 
	  if( coutF < nodeAdjacente->getF())
	  {
	    nodeAdjacente->setparent( centerNode);
	  }
	    
	}
	else//Sinon on l'ajoute a la liste ouverte
	{
	  addListeOuverte(nodeAdjacente);
	  //addListeOuverte( m_graph->findNode( tmpNode.getPosition().first, tmpNode.getPosition().second));
	}
      }
       
     }
    
  }
    
}

void PathFinder::retouverChemin()
{

}

void PathFinder::removeListeOuverte(Node* node)
{
  std::vector<Node*>::iterator it = std::find( m_listeOuverte.begin(), m_listeOuverte.end(), node);
  m_listeOuverte.erase( it);
  std::cout << "Node supprimer a la liste ouverte " << (*it)->getChar() << "," << (*it)->getAdresse() << std::endl;
}

void PathFinder::removeListeFermee(Node* node)
{
    std::vector<Node*>::iterator it = std::find( m_listeFermee.begin(), m_listeFermee.end(), node);
    m_listeFermee.erase( it);
    std::cout << "Node supprimer a la liste fermee "<< (*it)->getChar() << "," << (*it)->getAdresse() << std::endl;
  
}


void PathFinder::addListeOuverte(Node* node)
{
<<<<<<< HEAD
  m_listeOuverte.push_back( node);
  std::cout << "Node ajouter a la liste ouverte "<< node->getChar() << "," << node->getAdresse() << std::endl;
=======
  std::pair<int, int> tmpPos= centerNode->getPosition();
  int x= tmpPos.first;
  int y= tmpPos.second;
  /*Pour chaque node en x adjacents*/
  for(int i= x-1; i <= x+1; i++);
    //Si en dehors de la map on arrete
  /*Pour chaque node en y adjacents*/
>>>>>>> 3664475d9867f64fe503bf4ef81f17cc7f81de48
}


void PathFinder::addListeFremee(Node* node)
{
  m_listeFermee.push_back( node);
  std::cout << "Node ajouter a la liste fermée "<< node->getChar() << "," << node->getAdresse() << std::endl;
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
<<<<<<< HEAD
 
    /* carré de la distance euclidienne pour int */
=======

    /* carré de la distance euclidienne */
>>>>>>> 3664475d9867f64fe503bf4ef81f17cc7f81de48
    /* return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); */
}


Node* PathFinder::getBestNodeListeOuverte()
{
<<<<<<< HEAD
  Node* tmp= m_listeOuverte[0];
  std::vector<Node*>::iterator it;
  
  for(it = m_listeOuverte.begin(); it!= m_listeOuverte.end(); it++) 
=======
  Node* tmp= 0;
  std::vector<Node*>::iterator it= m_listeOuverte.begin();

  for(it = m_listeOuverte.begin(); it!= m_listeOuverte.end(); it++)
>>>>>>> 3664475d9867f64fe503bf4ef81f17cc7f81de48
  {
    std::cout << "Comparaison cout node" << "\t";
    std::cout<< "cout F tmp: "<< tmp->getChar() << "," << tmp->getF();
    std::cout << " || cout F it: " << (*it)->getChar() << "," << (*it)->getF() << std::endl; 
    if(tmp->getF() > (*it)->getF())
    {
      tmp = (*it);
      std::cout << "Meilleur Node trouvé " << tmp->getChar() << "," << tmp->getAdresse() << std::endl; 
    }
      
  }

  return tmp;

}






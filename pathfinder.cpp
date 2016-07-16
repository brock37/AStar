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

std::list< std::pair<int, int> > PathFinder::findPath()
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
   std::pair<int, int> current= m_nodeDepart;
   addListeOuverte(current);
   addListeFermee( current);
   addAdjacentNodeListeOuverte( current);
   
   while( !((current.first == m_nodeArrive.first) && (current.second == m_nodeArrive.second)) && (!m_listeOuverte.empty()) )
   {
     current= getBestNodeListeOuverte();
     
     addListeFermee( current);
     
     addAdjacentNodeListeOuverte(current);
   }

  return retouverChemin();

}



void PathFinder::addAdjacentNodeListeOuverte(std::pair<int, int> centerNode)
{
    int x= centerNode.first;
    int y= centerNode.second;
    Node tmp;

    for(int i=x-1 ; i <= x+1; i++)
    {
        if( (i < 0) || (i > m_graph->getNombreLigne()))
            continue;
        for(int j=y-1 ; j <= y+1; j++)
        {
            if( (j < 0) || (j > m_graph->getNombreColonne()))
                continue;
            if( i == x && j == y)
                continue;
            if(m_graph->findNode(i,j).getWalkable() == false)
                continue;

           std::pair<int, int> it(i,j);
	   if(!inListeFermee( it))
	   {
	     tmp.setG( m_listeFermee[centerNode].getG() + distanceNoeud(i,j, centerNode.first, centerNode.second));
	     tmp.setH( distanceNoeud(i,j, m_nodeArrive.first, m_nodeArrive.second));
	     tmp.setF( tmp.getG() + tmp.getH());
	     
	     tmp.setparent( centerNode);
	     tmp.setwalkable( m_graph->findNode(i,j).getWalkable());
	     tmp.setChar( m_graph->findNode(i,j).getChar());
	     
	     if(inListeOuverte(it))
	     {
	       if(tmp.getF() < m_listeOuverte[it].getF())
		 m_listeOuverte[it]= tmp;
	     }
	     else
	     {
	       //on ajoute la node la liste ouverte
	       m_listeOuverte[std::pair<int, int>(i, j)]= tmp;
	     }
	  }
	}
    }
}

std::list< std::pair<int, int> > PathFinder::retouverChemin()
{
    std::list< std::pair<int, int> > chemin;
    
    Node& tmp_node= m_listeFermee[m_nodeArrive];
    
    std::pair<int, int> node= m_graph->getNodePosition(tmp_node.getChar());
    std::pair<int, int> prec(tmp_node.getParent());
    
    
    chemin.push_back( m_nodeArrive);
    
    while( prec != m_nodeDepart)
    {
      node.first= prec.first;
      node.second= prec.second;
      
      chemin.push_back( node);
      
      tmp_node= m_listeFermee[ tmp_node.getParent()];
      prec= tmp_node.getParent();
      
    }
    
    
    listerNode( chemin);
    return chemin;
}

void PathFinder::removeListeOuverte(std::pair<int, int> node)
{
  if(m_listeOuverte.erase( node) == 0)
  {
    std::cerr << "Erreur, le noeud n'apparait pas dans la liste ouverte, impossible à supprimer" << std::endl;
  }
}

void PathFinder::updateListeOuverte(std::pair< int, int > node, Node tmp_node)
{
  Node& update_node= m_graph->findNode( node.first, node.second);
  update_node.setF( tmp_node.getF());
  update_node.setG( tmp_node.getG());
  update_node.setH( tmp_node.getH());
}


void PathFinder::addListeOuverte(std::pair<int, int> node)
{
    m_listeOuverte[std::pair<int, int>(node)]= m_graph->findNode(node.first, node.second);
}

void PathFinder::addListeFermee(std::pair<int, int> node)
{
    //m_listeFermee[std::pair<int, int>(node)]= m_graph->findNode(node.first, node.second);
  Node& n=  m_listeOuverte[node];
  m_listeFermee[node]= n;

  removeListeOuverte( node);

}

bool PathFinder::inListeOuverte(std::pair<int, int> node)
{
    if(m_listeOuverte.find( node) != m_listeOuverte.end())
        return true;
    return false;
}

bool PathFinder::inListeFermee(std::pair<int, int> node)
{
    if(m_listeFermee.find( node) != m_listeFermee.end())
        return true;
    return false;
}

float PathFinder::distanceNoeud(int x1, int y1, int x2, int y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
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
    float tmpCout_F= m_listeOuverte.begin()->second.getF();
    std::pair<int, int> bestNode(m_listeOuverte.begin()->first);
    std::map< std::pair<int,int> , Node>::iterator it;
    for(it = m_listeOuverte.begin(); it != m_listeOuverte.end(); it++)
    {
        if(it->second.getF() < tmpCout_F)
        {
            tmpCout_F= it->second.getF();
            bestNode= it->first;
        }
    }
    return bestNode;
}

void PathFinder::listerNode(std::list< std::pair< int, int > > liste)
{
  std::list< std::pair< int, int > >::iterator it;
  for(it = liste.begin(); it!= liste.end(); it ++)
    std::cout << m_graph->findNode(it->first, it->second).getChar()  << "," ;
    //std::cout << it->first  << "," << it->second << std::endl;
}


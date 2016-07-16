#include "graph.h"

Graph::Graph(int hauteur, int largeur)
{
  m_nombreLigne= hauteur;
  m_nombreColonne= largeur;
  
}

Graph::Graph(const Graph& other)
{

}

Graph::~Graph()
{

}

void Graph::initGraph()
{
  char c= 'a';
  for(int i=0; i < m_nombreLigne; i++)
  {
    for(int j=0; j < m_nombreColonne; j++)
    {
      m_graph[std::pair<int, int>(i,j)]= Node(i,j,c);
      std::cout <<  m_graph[std::pair<int, int>(i,j)].getChar() << "," <<  m_graph[std::pair<int, int>(i,j)].getAdresse() << std::endl;
      c++;
    }
  }
}

void Graph::afficherGraph()
{
  for(int i=0; i < m_nombreLigne; i++)
  {
    for(int j=0; j < m_nombreColonne; j++)
    {
      std::cout << m_graph[std::pair<int, int>(i,j)].getChar();
    }
    std::cout << std::endl;
  }
}

Node& Graph::findNode(int x, int y)
{/*
  std::pair <int, int> findpos(x,j);
  std::map< std::pair<int,int> , Node>::iterator it;
  for(it= m_graph.begin(); it != m_graph.end(); it++)
  {
    if( findpos == it->first )
    return it->second;
  }
  */
  Node& tmp= m_graph[std::pair<int, int>(x,y)];
  return tmp;
}

Node& Graph::findNode(std::pair<int, int> pos)
{
  Node& tmp= m_graph[pos];
  return tmp;
}

std::pair< int, int > Graph::getNodePosition(int x, int y)
{
  std::pair <int, int> findpos(x,y);
  std::map< std::pair<int, int> , Node>::iterator it;
  
  for(it= m_graph.begin(); it != m_graph.end(); it++)
  {
    if( findpos == it->first )
    return it->first;
  }
}

std::pair< int, int > Graph::getNodePosition(char c)
{
  std::map< std::pair<int, int> , Node>::iterator it;
  
  for(it= m_graph.begin(); it != m_graph.end(); it++)
  {
    if( c == it->second.getChar() )
    return it->first;
  }
}





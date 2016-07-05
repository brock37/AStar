#include "graph.h"

Graph::Graph(int l, int c)
{
  m_nombreLigne= l;
  m_nombreColonne= c;
  
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
      m_graph[std::pair<int, int>(i,j)]= new Node(i,j,c);
      std::cout <<  m_graph[std::pair<int, int>(i,j)]->getChar() << "," <<  m_graph[std::pair<int, int>(i,j)]->getAdresse() << std::endl;
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
      std::cout << m_graph[std::pair<int, int>(i,j)]->getChar();
    }
    std::cout << std::endl;
  }
}

Node* Graph::findNode(int x, int j)
{
  std::pair <int, int> findpos(x,j);
  std::map< std::pair<int,int> , Node*>::iterator it;
  for(it= m_graph.begin(); it != m_graph.end(); it++)
  {
    if( findpos == it->first )
    return it->second;
  }
  /*Node* tmp= m_graph.at(x * m_nombreLigne + j);
  //std::cout << "Node trouvé ardesse: " << tmp << std::endl;
  return tmp;*/
}




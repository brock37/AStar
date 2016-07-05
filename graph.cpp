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
  for(int i=0; i <m_graph.size(); i++)
  {
    std::cout << "Remove Pointer Ardess: "<<m_graph[i]->getChar() << "," << m_graph[i] << std::endl;
    delete m_graph[i];
  }
}

void Graph::initGraph()
{
  char c= 'a';
  for(int i=0; i < m_nombreLigne; i++)
  {
    for(int j=0; j < m_nombreColonne; j++)
    {
      m_graph.push_back(new Node(i,j, c));
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
      std::cout << m_graph[i* m_nombreLigne+j]->getChar();
    }
    std::cout << std::endl;
  }
}

Node* Graph::findNode(int x, int j)
{
  Node* tmp= m_graph.at(x * m_nombreLigne + j);
  //std::cout << "Node trouvé ardesse: " << tmp << std::endl;
  return tmp;
}




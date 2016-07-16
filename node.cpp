#include "node.h"

Node::Node()
{
    m_F= m_G = m_H = 0;
    m_walkable= true;
}


Node::Node(int line, int col, char c= 'a')
{
  m_char= c;
  m_F= m_G = m_H = 0;
  m_walkable= true;
  m_position= std::pair<int, int>( line, col);

}

Node::Node(const Node& other):m_char(other.m_char),  m_G(other.m_G), m_H(other.m_H),m_F(other.m_F),
			      m_walkable(other.m_walkable), m_position(other.m_position), m_parent(other.m_parent)
{

}

Node& Node::operator=(const Node& other)
{
  if(this != &other)

    //On vérifie que l'objet n'est pas le même que celui reçu en argument

   {
    m_char= other.m_char;
    m_F=other.m_F;
    m_G =other.m_G;
    m_H =other.m_H;
    m_walkable= other.m_walkable;
    m_position= other.m_position;
    m_parent= other.m_parent;
   }

    return *this; //On renvoie l'objet lui-même
}



Node::~Node()
{

}

#ifndef NODE_H
#define NODE_H
#include <utility>

class Node
{
public:
Node(int line, int col, char c);
Node(const Node& other);
~Node();
Node& operator=(Node const& other);

void setChar(char c){m_char= c;};
void setG(float g){m_G=g;};//Cout du point de depart a la node
void setH(float h){m_H=h;};//Cout de la node au point darrive
void setF(float f){m_F=f;};//Somme des deux valeur g et h
void setwalkable(bool walk){m_walkable= walk;};
void setPosition(std::pair<int, int> pos){ m_position=pos;};
void setparent(Node* parent){m_parent= parent;};


char getChar(){return m_char;};
float getG(){return m_G;};
float getH(){return m_H;};
float getF(){return m_F;};
bool getWalkable(){return m_walkable;};
std::pair<int , int> getPosition(){return m_position;};
Node* getParent(){return m_parent;};
Node* getAdresse(){return this;};


private:
  char m_char;
  float m_G;//il s'agit de la distance parcourue depuis le point de départ pour arriver au node courant.
  float m_H;// il s'agit de la distance à vol d'oiseau entre le node courant et le node d'arrivée.
  float m_F;//Somme de H et G
  bool m_walkable;
  std::pair<int , int> m_position;
  Node* m_parent;
};

#endif // NODE_H

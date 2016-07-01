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

void setChar(int c){m_char= c;};
void setG(int g){m_G=g;};//Cout du point de depart a la node
void setH(int h){m_H=h;};//Cout de la node au point darrive
void setF(int f){m_F=f;};//Somme des deux valeur g et h
void setcolonne(int col){m_colonne= col;};
void setligne(int li){m_ligne= li;};
void setwalkable(bool walk){m_walkable= walk;};
void setPosition(std::pair<int, int> pos){ m_position=pos;};
void setparent(Node* parent){m_parent= parent;};

char getChar(){return m_char;};
int getG(){return m_G;};
int getH(){return m_H;};
int getF(){return m_F;};
int getColonne(){return m_colonne;};
int getLigne(){return m_ligne;};
bool getWalkable(){return m_walkable;};
std::pair<int , int> getPosition(){return m_position;};
Node* getParent(){return m_parent;};


private:
  char m_char;
  int m_G;//il s'agit de la distance parcourue depuis le point de départ pour arriver au node courant.
  int m_H;// il s'agit de la distance à vol d'oiseau entre le node courant et le node d'arrivée.
  int m_F;//Somme de H et G
  int m_colonne;
  int m_ligne;
  bool m_walkable;
  std::pair<int , int> m_position;
  Node* m_parent;
};

#endif // NODE_H


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>  //Estructura de dato vector, con push etc... ya implementado
using std::vector;


class Node;

class Node {
  public:
    int key;  
    Node *parent;
    vector < Node *> children;  //vector lo cual acceder a una posicion especifica es O(1)
    
    //constructor
    Node(){
      this->parent = nullptr;
    }
    
    //Establecer padre
    void setParent(Node *theparent){
      this->parent = theparent;
      this->parent->children.push_back(this);  //Analizar a lapiz y papel
    }    
};

void newTree(){
  int n;
  cin >> n;
  
  vector <Node> Nodos(n);  //Este seria el arbol
  
  for (int child_index =0 ; child_index < n ; child_index++){
    int parent_index;
    cin >> parent_index;  //4
    if(parent_index  == -1){
      Nodos[child_index].key = child_index;  //Nodo raiz
    }
    else{
      Nodos[child_index].setParent(&Nodos[parent_index]);  
    }  
  }  
}



int main()
{
  newTree();
  
  
  
  return 0;
}
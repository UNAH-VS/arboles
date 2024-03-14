#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>  //Estructura de dato vector, con push etc... ya implementado
using std::vector;
using std::max;  //Es para obtener el maximo  !Investigar!
#include <algorithm>  //Es una libreria con algoritmo optimos


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

vector<Node> newTree(){
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
      Nodos[child_index].key = child_index;
      Nodos[child_index].setParent(&Nodos[parent_index]);  
    }  
  }
  return Nodos;
}

void monstrarArbol(vector<Node> A){

  cout<<"IMPRMIENDO ARBOL: "<<endl;
  for (int i = 0; i < A.size(); i++)
  {
    cout<<"Padre: "<<i<<endl;
    vector<Node *> hijos = A[i].children;
    if(A[i].parent == NULL)
      cout<<"Raiz"<<endl;

    if(hijos.size() != 0){
      cout<<"Hijos: ";
      for (int h = 0; h < hijos.size(); h++)
      {
        cout<<hijos[h]->key<<" ";
      }
      cout<<endl;
    }
    else
      cout<<"Hoja"<<endl;
  }  
}

int  Height(vector<Node> A){ //Vector de hojas ?
  int altura;
  for(int indice_hoja = 0 ; indice_hoja<A.size() ; indice_hoja++)
  {
    int mi_altura=0;  // Para cada nodo calculamos la altura de ese nodo 
    for(Node *v= &A[indice_hoja] ; v != NULL ; v = v->parent){
      mi_altura++; //La altura "del nodo" es decir desde el nodo hasta la raiz  
    }
  if( mi_altura > altura ){
    altura = max(altura,mi_altura);
    altura=mi_altura;
  } 
  }
  
  
  return altura;
}

int main()
{
  vector<Node> arbol;
  arbol = newTree();
  monstrarArbol(arbol);
  cout<<" La altura del arbol  es :  "<< Height(arbol)<<endl;
  
  return 0;
}

//Recomendacion utilizar libreria vector
//Libreria <algorithm>
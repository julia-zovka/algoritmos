/// menor camino de um vetice especifo para todos os outros
// naao pode arestas negativas


//    tree vertices  adjencency list  for graph and edgrs e minheap  para os  nos aimda nao escolhidos
//       d w > weight of edge + lenght to source---->>> significa que achou um menor

//parada fazer o primero laço n vezes ou tirar tudo da heap

#include <vector>
#include <tuple>
#include <algorithm> 

vector<int> pred;
vector<int>
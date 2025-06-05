#include <vector>
#include <iostream>
using namespace std;

//implementacao com array
//bottom up - colocar toda a entrada e depois ajeitar
//minimo no
class Heap{
    private:
        int size;
    public:
        int insert(vector<int>& heap, int b){
            heap.push_back(b);
            size++;

        }

        void heaping(vector<int>& heap){
            for(int i=size/2;i<1;i--){
                int k=i;
                int v=heap[k];                          //chave
                bool ordem=false;                       //ta errado
                while( !ordem && 2*k<=size){            //náo estrapolar o tamanho da vetor
                int j=2*k;                              // posicao filho 1
                    if (j<size){                        //tem mais de um filho
                        if (heap[j]<heap[j+1]){
                            j=j+1;}}                    //posicao do filho maior
                                                        
                    if (v>=heap[j]){
                        ordem=true;}
                    else{
                        heap[k]=heap[j];//troca de lugares
                        k=j;}
                    }
                heap[k]=v;/// troca de lugar e bota o menor v que tava sendo analisado  no filho 
                }

            }

};

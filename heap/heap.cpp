#include <vector>
#include <iostream>
using namespace std;

//implementacao com array
//bottom up - colocar toda a entrada e depois ajeitar
//minimo no root


class Heap{
    private:
        int size;
        vector<int> heap;
    public:

        Heap(int n = 0) {
        size = n;
        heap.push_back(-1); // valor fictício no índice 0
        }

        void insert( int b){
                heap.push_back(b);

        }
        void heaping(){//bottom up~~~``~
            for(int i=size/2;i>=1;i--){
                int k=i;
                int v=heap[k];                         //chave
                bool ordem=false;                      //ta errado
                while( !ordem && 2*k<size){            //náo estrapolar o tamanho da vetor //saber se k [e um no interno  pq a comparacao [e entre o pai e seus filhos]
                int j=2*k;                             // posicao filho 1
                    if (j<size && heap[j]>heap[j+1] ){ //tem mais de um filho
                        j=j+1;}                        //posicao do filho maior
                                                        
                    if (v<=heap[j]){
                        ordem=true;}
                    else{
                        heap[k]=heap[j];//troca de lugares
                        k=j;}
                    }
                heap[k]=v;/// troca de lugar e bota o menor v que tava sendo analisado  no filho 
                //so no final que atualiza o valor de k porque pode mudar mais de uma vez
            }
        }

        void heapSort(){
            int qnt_vezes=size;
            for(int i=0;i<qnt_vezes;i++){
                int tchau=heap[1];
                int new_root=heap[size];
                heap[1]=new_root;
                heap[size]=tchau;
                size--;
                reheaping(1);   
            }

        }
        void reheaping(int i){
            int k=i;
            int v=heap[k];                          //chave
            bool ordem=false;                       //ta errado
            while( !ordem && 2*k<size){            //náo estrapolar o tamanho da vetor
                int j=2*k;                              // posicao filho 1
                if (j<size && heap[j]>heap[j+1] ){                        //tem mais de um filho
                    j=j+1;}                   //posicao do filho maior
                                                    
                if (v<=heap[j]){
                    ordem=true;}
                else{
                    heap[k]=heap[j];//troca de lugares
                    k=j;}
                }
            heap[k]=v;
        }


        void print(){
            for(int i=1;i<=size;i++){
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int casos, tamanho,num;
    cin>>casos;
    for(int i=0; i<casos;i++){
        cin>>tamanho;
        Heap heap(tamanho);
        for(int y=0; y<tamanho;y++){
            cin>>num;
            heap.insert(num);
        }
        heap.heaping();
        heap.print();
        heap.heapSort();
        heap.print();
    }
}
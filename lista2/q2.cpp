#include <vector>
#include <iostream>
using namespace std;

//implementacao com array
//bottom up - colocar toda a entrada e depois ajeitar


class Heap{
    private:
        int size;
        vector<int> heap;
    public:

        Heap() {
        size = 0;
        heap.push_back(-1); // valor fictício no índice 0
        }

        void insert(int b) {///top down 
            heap.push_back(b);
            size++;
            int k = size;
            while (k > 1 && heap[k / 2] < heap[k]) {/////compara se o pai [e ] menor
                swap(heap[k], heap[k / 2]);
                k = k / 2;
            }
        }

        void remove(){
             if (size > 0) {
            heap.pop_back();
            size--;
            }
        }
        void heaping(){//bottom up~~~  //// olha pro filho
            for(int i=size/2;i>=1;i--){
                int k=i;
                int v=heap[k];                         //chave
                bool ordem=false;                      //ta errado
                while( !ordem && 2*k<=size){            //náo estrapolar o tamanho da vetor //saber se k [e um no interno  pq a comparacao [e entre o pai e seus filhos]
                int j=2*k;                             // posicao filho 1
                    if (j<size && heap[j]<heap[j+1] ){ //tem mais de um filho
                        j=j+1;}                        //posicao do filho maior
                                                        
                    if (v>=heap[j]){
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
            int qnt_vezes=size-1;
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
            while( !ordem && 2*k<=size){            //náo estrapolar o tamanho da vetor
                int j=2*k;                              // posicao filho 1
                if (j+1<=size && heap[j]<heap[j+1] ){                        //tem mais de um filho
                    j=j+1;}                   //posicao do filho maior
                                                    
                if (v>=heap[j]){
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

        int popMaior(){
            int tchau=heap[1];
            heap[1]=heap[size];
            heap.pop_back();
            size--;
            reheaping(1);   
            return tchau;
        }
        
        int getSize(){
            return this->size;
        }
};

int main(){
    int casos, q_num, num;
    cin>>casos;
    for(int i=0;i<casos;i++){
        cin>>q_num;
        Heap heap;
        for(int j=0;j<q_num;j++){
            cin>>num;
            heap.insert(num);
        }
        //heap.heaping();
        
        int y=0;
        while(heap.getSize()>=2){
            int j=heap.popMaior();
            int j2=heap.popMaior();
            y=j+j2-1;
            heap.insert(y);
            //heap.heaping();
        }
        y=heap.popMaior();
        cout<<y<<endl;
    }
}
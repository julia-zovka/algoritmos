using namespace std;
#include <iostream>
#include <vector>


void merge(vector<int>& entrada, int inicio, int middle, int fim){

    //cria os dois vetores
    int n1 = middle - inicio + 1;
    int n2 = fim - middle;

    vector<int> A(n1), B(n2);

    for (int i = 0; i < n1; i++)
        A[i] = entrada[inicio + i];
    for (int j = 0; j < n2; j++)
        B[j] = entrada[middle +1+ j];
    
    //reeescreever o vetor original
    int iA = 0, iB = 0, k = inicio;

    while(iA< A.size() && iB <B.size()){// se for igual [e porque] j[a comparou o ultimo , começa do 0 e termona no size-1    }
        if(A[iA]<=B[iB]){
            entrada[k]=A[iA];
            iA++;
        }
        else{
            entrada[k]=B[iB];
            iB++;
        }
        k++;
    }

    // já acabopu açgum dos vetores
    while(iA<A.size()){
        entrada[k]=A[iA];
        iA++;
        k++;

    }
    while(iB<B.size()){
        entrada[k]=B[iB];
        iB++;
        k++;

    }
}

void mergeSort(vector<int>& entrada, int inicio, int fim) {   
    
    if(inicio<fim){
        
        int middle = inicio + (fim-inicio) / 2;
        mergeSort(entrada, inicio, middle);
        mergeSort(entrada, middle + 1, fim);
        merge(entrada, inicio, middle, fim);
    }
    
}

int main(){

    int casos, tamanho,num;
    cin>>casos;
    for(int i=0; i < casos; i++){
        cin>>tamanho;
        if(tamanho>1){
            vector<int> entrada;
            for(int j=0; j < tamanho;j++){
                cin>>num;
                entrada.push_back(num);
            }
            mergeSort(entrada, 0, entrada.size() - 1);

            for(int x : entrada){
                cout<<x<<" ";
            }
            cout<<endl;
        }   
        
        else{
            cin>>num;
            cout<<num<<endl;
        }

    }


};


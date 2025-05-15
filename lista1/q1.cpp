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
        
        //int middle = inicio + (fim-inicio) / 2;
        int middle=(inicio+fim)/2;
        mergeSort(entrada, inicio, middle);
        mergeSort(entrada, middle + 1, fim);
        merge(entrada, inicio, middle, fim);
    }
    
}


//lista com 2n numeros, aplica algoritmo de ordenacao e soma 
int main(){

    int caso, n, num, soma;
    cin>>caso;
    for(int i =0;i<caso;i++){
        soma=0;
        cin>>n;
        vector<int> lista(2*n);
        for(int j=0; j<2*n;j++){
            cin>>num;
            lista[j]=num;
        }
        mergeSort(lista,0,lista.size()-1);
        //soma
        for(int s=0; s<n; s++){//tenho n tentativas
            soma+=lista[lista.size()-2];//o menor entre os maiores
            //tira os dois da lista
            lista.pop_back();
            lista.pop_back();
        }
        cout<<soma<<endl;
    }
}
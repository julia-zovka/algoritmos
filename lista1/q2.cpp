using namespace std;
#include <iostream>
#include <vector>


int binarySearch(vector<int>& A,int l, int r, int k){
    //l=0;
    //r=A.size()-1;
    if(r>=l){
        int middle=(l+r)/2;
        if(k==A[middle]){
            return middle;}
        else if(k<A[middle]){
            return binarySearch(A,l,middle-1, k);}
        else{//maior}
             return binarySearch(A,middle+1,r,k);}

    }
    else{
        return -1;
    }
}

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
int main(){
    int q_num,num, k,pares;
    pares=0;
    cin>>q_num;
    cin>>k;
    vector<int> A;
    for(int i=0; i<q_num;i++){
        cin>>num;
        A.push_back(num);
    }
    mergeSort(A,0,A.size()-1);
    //achar o numero i somado a k
    for(int x:A){
        int res=binarySearch(A, 0, A.size()-1, x+k);
        if(res!=-1){//achou um par que a diferen;a de a chave
            pares+=1;}
    }
    cout<<pares<<endl;

    }
using namespace std;
#include <iostream>
#include <vector>

int partition(vector<int>& lista, int l, int r){
    int i=l+1;
    int j=r;
    int p=lista[l];

    //comeca a escanear do seggundo, o primeiro [e o pivot]
    //i left-right
    //j right to left
    while(i<j){
        while (lista[i]<p && i<r){// para se maior ou igualk ao pivot
            i++;}
        
        while(lista[j]>p){
            j--;}
        //ai e aj
        int temp;
        temp=lista[i];
        lista[i]=lista[j];
        lista[j]=temp;
    }
    //desfaz
    int temp2;
    temp2=lista[i];
    lista[i]=lista[j];
    lista[j]=temp2;
    
    //al e aj
    int temp3;
    temp3=lista[l];
    lista[l]=lista[j];
    lista[j]=temp3;
    return j;

}

void quickSort(vector<int>& lista, int l, int r){
    //o s j[a fica no lufgar certo
    if (l<r){
        int s=partition(lista, l, r);
        quickSort(lista, l, s-1);
        quickSort(lista, s+1, r);
    }

}


int main(){
    int casos, tamanho, num;
    cin>>casos;
    for(int i=0;i<casos; i++){
        vector<int> lista;
        cin>>tamanho;
        for(int x=0; x<tamanho;x++){
            cin>>num;
            lista.push_back(num);    
        }
        quickSort(lista, 0, lista.size()-1);
        while(!lista.empty()){
            int o=*lista.rbegin();
            cout<<o<<" ";
            lista.pop_back();
        }
        cout<<endl;
    }

}
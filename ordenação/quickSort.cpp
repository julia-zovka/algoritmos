using namespace std;
#include <iostream>
#include <vector>

int partition(vector<int>& lista, int l, int r){
    int i=l;
    int j=r+1;
    int p=lista[l];
    int temp;

    //comeca a escanear do seggundo, o primeiro [e o pivot]
    //i left-right
    //j right to left
    do {
        do{
            i++;
        }while(lista[i]<p && i<r);
        do{
            j--;
        }while(lista[j]>p);
        temp=lista[i];
        lista[i]=lista[j];
        lista[j]=temp;     
    }while(i<j);

    temp=lista[i];
    lista[i]=lista[j];
    lista[j]=temp; 
    //al e aj
    temp=lista[l];
    lista[l]=lista[j];
    lista[j]=temp;
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

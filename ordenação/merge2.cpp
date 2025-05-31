#include <vector>
#include <iostream>
using namespace std;




void merge(vector<int>& A, int l,int m, int r){
    vector<int> temp(A.size()-1);
    for(int i=l;i<=r;i++){
        temp[i]=A[i];
    }
    int i1=l;
    int i2=m+1;
    for(int curr=l;curr<r;curr++){
        if (i1==m+1){
            A[curr]=temp[i2++];}
        else if(i2>r){
            A[curr]=temp[i1++];}
        else if (temp[i1]<=temp[i2]){
            A[curr]=temp[i1++];}
        else{
            A[curr]=temp[i2++];}
    }


}


void mergeSort(vector<int>& A, int l, int r){
    if (l<r){
        int m=(l+r)/2;
        mergeSort(A,l, m);
        mergeSort(A,m+1,r);
        merge(A,l,m,r);
    }

}


int main(){

    int casos, tamanho,num;
    cin>>casos;
    for(int i=0; i < casos; i++){
        cin>>tamanho;
        if(tamanho>1){
            vector<int> A;
            for(int j=0; j < tamanho;j++){
                cin>>num;
                A.push_back(num);
            }
            mergeSort(A, 0, A.size() - 1);

            for(int x : A){
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
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

int main(){
    int tamanho,num,q_chaves,chave;
    vector<int> A;
    cin>>tamanho;
    for(int i =0; i<tamanho; i++){
        cin>>num;
        A.push_back(num);
    }
    cin>>q_chaves;
    for(int j=0; j<q_chaves;j++){
        cin>>chave;
        int c=binarySearch(A,0, A.size()-1, chave);
        if (c==-1){
            cout<<"x"<<endl;}
        else{
        cout<<c<< endl;}
    }

}
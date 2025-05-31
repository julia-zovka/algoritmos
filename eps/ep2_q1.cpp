#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



int binarySearch(vector<string>& A, int l, int r , string k){
    if(r>=l){
        int m= (l+r)/2;
        if(A[m]==k){
            return m;
        }
        else if(k>A[m]){
            return binarySearch(A,m+1,r, k);
        }
        else{
            return binarySearch(A,l, m-1, k);
        }
    }
    else{
        return -1;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int qpalavras, qchutes;
    int acertos=0;
    string palavra, chute;
    vector<string> dic;
    cin>>qpalavras;
    for(int i=0;i<qpalavras;i++){
        cin>>palavra;
        dic.push_back(palavra);
    }
    cin>>qchutes;
    for(int t=0; t<qchutes;t++){
        cin>>chute;
        int c=binarySearch(dic,0, dic.size()-1, chute);
        if(c!=-1){
            acertos++;}
    }
    cout<<acertos<<"\n";

}

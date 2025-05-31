#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



int binarySearch(vector<int>& A, int l, int r , int k){
    int m= (l+r)/2;
    if(r>=l){
        //int m= (l+r)/2;
        if(A[m]==k){
            return m;
        }
        else if(k>A[m]){//maior
            if(abs(k-A[m+1])<=abs(k-A[m])){
                return binarySearch(A,m+1,r, k);}
            else{
                return m;
            }
        }
        else{//menor
            if(abs(k-A[m-1])<=abs(k-A[m])){// se o anterior ao meio é mais proximo chama a funcao
                return binarySearch(A,l, m-1, k);}
            else{
                return m;
            }
        }
    }
    else{
      return m;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q_num,num, q_query, query, proximo;
    vector<int> nums;

    cin>>q_num;
    for(int i=0;i<q_num;i++){
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    cin>>q_query;

    for(int j=0;j<q_query;j++){
        cin>>query;
        proximo=binarySearch(nums,0,nums.size()-1,query);
        cout<<nums[proximo]<<"\n";
    }

}

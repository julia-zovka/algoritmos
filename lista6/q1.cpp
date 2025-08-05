#include <vector>
#include <iostream>
#include <climits>
using namespace std;

//bottom up

int main(){
    int n, num, sum,resposta;
 
    cin>>n>>sum;

    vector<int> coins;
    vector<int> v_sum (sum+1,INT_MAX);///valores que quero dar troco, 0- sum da questáo
    // f do livro
    v_sum[0]=0;// zero moedas pro valor 0


    ///posisiveis moedas pro toroc
    // d do livro
    for(int i=0;i<n;i++){
        cin>>num;
        coins.push_back(num);
    }

  

    //j [e o indice que vi passear pelas coins
    //i [e o que vai oassear pelas valores

    /// troca pra seis usando uma moedinha da menor depois usando uma moedinha da emdia e vai subindo +1 que [e esa final]
    int j;
    for(int i=1;i<=sum;i++){
        j=1;
        for(int j=0;j<n;j++){
            if(i>=coins[j] && v_sum[i - coins[j]] != INT_MAX){// como [e bottom up o anteriro ja t[a calculado]]
                v_sum[i]=min(v_sum[i], v_sum[i-coins[j]]+1);
            }
        }
        //vSum[i]=f(n-dj)+1
    }

    resposta=v_sum[sum];
    if(resposta == INT_MAX){cout<<-1<<endl;}
    else{cout<<resposta<<endl;}

}
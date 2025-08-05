#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long l_original, l_new, cost_in, cost_rem, cost_mod, cost;
    cin>> l_original>> l_new>>cost_in>>cost_rem>> cost_mod;

    vector<vector<long long >> operacao(l_original+1, vector<long long>(l_new+1));

    string ogP, newP;
    cin>>ogP>>newP;
    for(int i=0;i<=l_original;i++){//custo pra deletar tudoo
        operacao[i][0]=i*cost_rem;
    }

    for(int j=0;j<=l_new;j++){//cusot pra inserir tudo
        operacao[0][j]=j*cost_in;
    }

    for(int i=1;i<=l_original;i++){
        for(int j=1;j<=l_new;j++){
            if(ogP[i-1]==newP[j-1]){
                operacao[i][j]=operacao[i-1][j-1];
            }
            else{
                operacao[i][j]=min({operacao[i-1][j]+cost_rem, operacao[i][j-1]+cost_in, operacao[i-1][j-1]+cost_mod});
            }
        }
    }

    cost=operacao[l_original][l_new];
    cout<<cost<<endl;
}
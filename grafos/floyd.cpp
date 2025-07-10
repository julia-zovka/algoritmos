#include <vector>
using namespace std;

/// desintegtra a matriz original
vector<vector<int>> grafo;
grafo.assign(n, vector<int>(n));
int n;

void floyd(vector<vector<int>> &grafo, int n){

    for(int k=0;k<n;k++){
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                grafo[i][j]=min(grafo[i][j], grafo[i][k]+grafo[k][j]);
            }
        }
    }

};
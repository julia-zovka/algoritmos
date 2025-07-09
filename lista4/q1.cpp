/// menor camino de um vetice especifo para todos os outros
// naao pode arestas negativas


//    tree vertices  adjencency list  for graph and edgrs e minheap  para os  nos aimda nao escolhidos
//       d w > weight of edge + lenght to source---->>> significa que achou um menor

//parada fazer o primero laço n vezes ou tirar tudo da heap
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;


void dijkstra(vector<vector<pair<int,int>>> &grafo, int s, vector<int> &distance, vector<int> &mark, vector<int> &pred,int n){
    

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;    
    heap.push({0,s,s});// distancia,pre,atual 
    distance[s]=0;

    int dist,p,v;// pre e v é o atual  -- essas informaçoes ficam na heap junto ocm diatancia
    for(int i=0;i<n;i++){
        do{
            if(heap.empty()){return;};
            tie(dist,p,v)=heap.top();
            heap.pop();
        }while(mark[v]==1);// qusnod achar um que não foi visitado
    
        mark[v]=1;
        pred[v]=p;
        for(auto [proximo,peso]: grafo[v]){/// first e next de v
            if (mark[proximo]!=1 && distance[proximo]> distance[v]+peso){
                distance[proximo]=distance[v]+peso;
                heap.push({distance[proximo],v,proximo});
            }
        }
    }
}


void setEdgee(vector<vector<pair<int,int>>> &grafo, int i, int j, int w){
            if(w==0){return;}
            grafo[i].push_back({j,w});
            grafo[j].push_back({i,w});
        }

int main(){
    int cases,n,m,s,t,a,b,w;
    cin>>cases;
    for(int r=0;r<cases;r++){

        cin>> n >> m >>s>>t;

        vector<vector<pair<int,int>>> grafo;
        vector<int> pred;
        vector<int> mark;
        vector<int> distance;

        pred.assign(n,-1);
        mark.assign(n,0);
        distance.assign(n,INT_MAX);
        grafo.resize(n);


        for(int i=0;i<m;i++){
            cin>> a >> b >>w;
            setEdgee(grafo,a,b,w);
        }
        dijkstra(grafo, s, distance,mark, pred, n);
        if(m==0){cout<<"Case #"<<r+1<<": unreachable"<<endl;}      


        else{
            int res=distance[t];
            if(res==-1){
                cout<<"Case #"<<r+1<<": unreachable"<<endl;}      
            else{
                cout<<"Case #"<<r+1<<": "<<res<<endl;}
        }
    }
}
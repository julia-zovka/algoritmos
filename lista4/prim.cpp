#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;


void prim(vector<vector<pair<int,int>>> &grafo, int s, vector<int> &distance, vector<int> &mark, vector<int> &pred,int n){
    

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;    
    heap.push({0,s,s});// distancia,pre,atual 
    distance[s]=0;

    int dist,p,v;// pre e v é o atual  -- essas informaçoes ficam na heap junto ocm diatancia
    for(int i=0;i<n;i++){
        do{
            if(heap.empty()){return;};
            tie(dist,p,v)=heap.top();
            heap.pop();
            //if(v==NULL){return;}
        }while(mark[v]==1);// qusnod achar um que não foi visitado
    
        mark[v]=1;
        pred[v]=p;
        for(auto [proximo,peso]: grafo[v]){/// first e next de v
            if (mark[proximo]!=1 && distance[proximo]> peso){
                distance[proximo]=peso;
                heap.push({distance[proximo],v,proximo});
            }
        }
    }
}


void setEdgee(vector<vector<pair<int,int>>> &grafo, int i, int j, int w, int numEdge){
            if(w==0){return;}
            grafo[i].push_back({j,w});
            grafo[j].push_back({i,w});
            numEdge++;
        }
bool conexo(vector<int> &distance){
    for(int dist:distance){
        if(dist==INT_MAX){
            return false;
        }
    }
    return true;
}

int main(){
    int n,e,s,d,a,b,w;
    cin>> n >> e;
    int numEdge;

    vector<vector<pair<int,int>>> grafo;
    vector<int> pred;
    vector<int> mark;
    vector<int> distance;
    while(n!=0 && e!=0){
        pred.assign(n,-1);
        mark.assign(n,0);
        distance.assign(n,INT_MAX);


        grafo.resize(n);
        for(int i=0;i<e;i++){
            cin>> a >> b >>w;
            setEdgee(grafo,a,b,w, numEdge);
        }
        cin>>s>>d;
        
        prim(grafo, s, distance,mark, pred, n);
        

        int meio=pred[d];
        int maior=INT_MIN;
        while(meio!=s && meio!= -1){// sem predecessor
            if(distance[meio]>maior){
                maior=distance[meio];}
            meio=pred[meio];
        }
        bool caminho=false;
        if(meio==s){caminho=true;}
        if(caminho){cout<<maior<<endl;}
        if(caminho==false || numEdge<(n*(n-1))){cout<<"IMPOSSIBLE"<<endl;}
        cin>>n>>e;
    }
}
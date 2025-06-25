#include <iostream>
#include<vector>
#include <queue>
#include <stack>
using namespace std;

class Graphs{
    private:
        vector<vector<pair<int,int>>> lista;
        vector<int> mark;
        int numEdge;
        int numV;

    public:
        Graphs(int n ){
            lista.resize(n);
            mark.assign(n, 0);
            this->numEdge=0;
            this->numV=n;
        }

        int first(int v){
            if (!lista[v].empty()){
                return lista[v][0].first;}
            return numV;
        }

        int next(int v, int w) {
            for (int i = 0; i < lista[v].size(); i++) {
                if (lista[v][i].first == w) {//acha w
                    if (i + 1 < lista[v].size()) {// ve se tem proximo
                        return lista[v][i+1].first;  
                    }
                }
            }
            return numV;  // Não encontrou w ou não tem próximo
        }

        void setEdge(int i, int j, int w){
            if(w==0){return;}
            lista[i].push_back({j,w});
            numEdge++;
        }

        void delEdge(int i, int j){
            bool achou=false;
            for (auto it = lista[i].begin(); it != lista[i].end(); ++it){
                if (it->first == j) {
                    achou=true;
                    lista[i].erase(it);
                }
            }
            numEdge--;
        }

        void setMark(int v, int x){
            mark[v]=x;
        }

        int getMark(int v){
            return mark[v];
        }

        void traverse1(int v){
           for( int i=0;i<numV;i++){
                setMark(i,0);//marcar como náo visitado
            }
            for( int i=v;i<numV;i++){
                if(getMark(i)==0){
                    DFS(i);
                };
            }  
        }
       

        void traverse2(int v){
           for( int i=0;i<numV;i++){
                setMark(i,0);//marcar como náo visitado
            }
            for( int i=v;i<numV;i++){
                if(getMark(i)==0){
                    BFS(i);
                };
            }  
        }

         void traverse3(int v){
           for( int i=0;i<numV;i++){
                setMark(i,0);//marcar como náo visitado
            }
            stack<int> s; 
            for( int i=v;i<numV;i++){
                if(getMark(i)==0){
                    topSort(i, s);
                };
            }
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }  
        }

        void preVisit(int v){
            cout<<v<<" ";
        }

        void DFS(int v){
            preVisit(v);//printar a ordem em que foram visitados
            setMark(v, 1);
            int w= first(v);
            while(w<numV){
                if(getMark(w)==0){
                    DFS(w);}
                w=next(v, w);
            }
        }

        void BFS(int v){
            queue<int> Q;
            Q.push(v);
            setMark(v,1);
            while(!Q.empty()){
                int v=Q.front();
                Q.pop();//tira do começo
                preVisit(v);

                int w=first(v);//vizinhos ve de 
                while(w<numV){
                    if(getMark(w)==0){
                        setMark(w,1);
                        Q.push(w);
                    }
                    w=next(v,w);
                }
            }
        }

        void topSort(int v, stack<int>& s){
            setMark(v,1);
            int w=first(v);
            while(w<numV){
                if(getMark(w)==0){
                    topSort(w,s);
                }
                w=next(v,w);
            }
            s.push(v);
        }

};

int main(){
    int ver, are,f,s;
    cin>>ver;
    cin>>are;
    Graphs grafo(ver);
    for(int i=0; i<are; i++){
        cin>>f;
        cin>>s;
        grafo.setEdge(f,s,1);

    }
    grafo.traverse3(0);
}

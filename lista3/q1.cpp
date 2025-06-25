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

        void setEdge(int i, int j, int w, bool &ciclos){
            if(w==0){return;}
            for (auto it = lista[j].begin(); it != lista[j].end(); ++it){// ver se acha i na lista j - indicalaço de ciclo
                if (it->first == i) {
                    ciclos=true;
                    return;
                }
            }
            find(j, i, ciclos);
            if (ciclos==true){return;}// nao coloca  a aresdta, tem ciclooo            
            lista[i].push_back({j,w});
            numEdge++;
        }

        void find(int i, int j, bool &achou ){
            int w= first(i);
            while(w<numV){
                if(w!=j){//não forem iguais, continua procurando
                    find(w,j,achou);}
                else{achou=true;}
                w=next(i, w);        
            }
        }



        /*void DFS(int v){
            preVisit(v);//printar a ordem em que foram visitados
            setMark(v, 1);
            int w= first(v);
            while(w<numV){
                if(getMark(w)==0){
                    DFS(w);}
                w=next(v, w);
            }
        }*/

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
    int cases, users, screenshots, começo, num;
    cin>>cases;
    for(int i=0; i<cases; i++){
        cin>>users;
        bool ciclos = false;
        Graphs grafo(users);
        cin>>screenshots;
        for(int b=0; b<screenshots; b++){
            cin>>começo;//lixo
            vector<int> numeros_p_g;
            for(int r=0; r<users-1; r++){
                cin>>num;
                numeros_p_g.push_back(num);
            }
            for(int r=0; r<numeros_p_g.size()-1; r++){// setando as edges de cad screenshot e ver se da conflito
                grafo.setEdge(numeros_p_g[r], numeros_p_g[r+1], 1, ciclos);
            }
        }
        if(ciclos){
            cout<<"NO"<<endl;
        }
        else{cout<<"YES"<<endl;}

    }
}

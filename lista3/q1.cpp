#include <iostream>
#include<vector>
#include <queue>
#include <stack>
using namespace std;

class Graphs{
    private:
        vector<vector<int>> lista;
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
                return lista[v][0];
            }
            return numV;
        }
 
        int next(int v, int w){
            for( int i=0; i<lista[v].size(); i++){//achar o w primeirooo
                if (lista[v][i]==w){
                    if(i+1<lista[v].size()){
                        return lista[v][i+1];
                    }//tem alguem depois do w
                }
            }
            return numV;
        }

        void setEdge(int i, int j){
            for (int v : lista[i]) {
                if (v == j) return; // já existe, não adiciona de novo
            }
            lista[i].push_back(j);
            numEdge++;
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

        bool transversemodfied(){
            vector<int> estado;
            estado.assign(numV, 0);
            for(int j=0;j<numV;j++){
                if(estado[j]==0){
                    if(ciclo(j, estado)){
                        return true;
                    }
                }
            }
            return false;
        }

        bool ciclo(int v, vector<int> &estado){///// 0 nao visitado        1 em procesaemnt      2 terminou
            estado[v]=1;//em processamento
            for(int vizinho : lista[v]){
                if(estado[vizinho]==1){return true;}//tem ciclo
                if(estado[vizinho]==0 && ciclo(vizinho, estado)){return true;}
            }
            estado[v]=2;
            return false;
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
    int cases, users, screenshots,num;
    cin>>cases;
    for(int i=0; i<cases; i++){
        cin>>users;
        cin>>screenshots;

        if(users==1 || users==2){
            int lixo;
            for(int b=0; b<screenshots; b++){
                for(int r=0; r<users; r++){
                    cin >> lixo;
                }
            }
            cout<<"YES"<<endl;
            continue;}
        Graphs grafo(users);
        for(int b=0; b<screenshots; b++){
            vector<int> numeros_p_g;
            cin>>num;

            for(int r=0; r<users-1; r++){
                cin>>num;
                numeros_p_g.push_back(num-1);
            }
            for(int r=0; r<users-2;r++){// setando as edges de cad screenshot e ver se da conflito
                grafo.setEdge(numeros_p_g[r], numeros_p_g[r+1]);
            }
        }        
        if(grafo.transversemodfied()){cout<<"NO"<<endl;}
        else{
            cout<<"YES"<<endl;
        }
       

    }
}

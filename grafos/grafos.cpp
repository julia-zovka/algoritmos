#include <iostream>
#include<vector>
#include <queue>
#include <stack>
using namespace std;

class Graphs{
    private:
        vector<vector<int>> matrix;
        vector<int> mark;
        int numEdge;
        int numV;

    public:
        Graphs(int n ){
            matrix.assign(n, vector<int>(n, 0));
            mark.assign(n, 0);
            this->numEdge=0;
            this->numV=n;
        }

        int first(int v){
            for(int i=0; i<numV;i++){
                if (matrix[v][i]!=0){return i;}
            }
            return numV;
        }
        int next(int v, int w){//depois do no w 
            for(int i=w+1;i<numV;i++){
                if (matrix[v][i]!= 0){return i;}
            }
            return numV;//não existe proximo, nenhum vertice vai ter esse valor
            //retorna o indice que representa o no
        }

        void setEdge(int i, int j, int w){
            if(w==0){return;}
            if(matrix[i][j]==0){
                numEdge++;
            }
            matrix[i][j]=w;
        }

        void delEdge(int i, int j){
            if(matrix[i][j]!=0){
                numEdge--;
            }
            matrix[i][j]=0;
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
    int n, q,i,j;
    string op;
    cin>>n;
    cin>>q;
    Graphs grafo(n);
    for(int t=0;t<q;t++){
        cin>>op;
        if(op=="add"){
            cin>>i;
            cin>>j;
            grafo.setEdge(i,j,1);
        }
        else if(op=="BFS"){
            cin>>i;
            grafo.traverse2(i);
            cout<<endl;
        }
        else{
            cin>>i;
            grafo.traverse1(i);
            cout<<endl;
        }
    }
}


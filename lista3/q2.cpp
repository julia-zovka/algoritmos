#include <iostream>
#include<vector>
#include <queue>
#include <stack>
using namespace std;


///////// BSFFF

//////// SE TIVER MARCODO NO MARK PRINTA NA MATRIZ NO FINAL

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
 
 
 
 
 
class Graphs{
    private:
        vector<vector<int>> lista;
        vector<int> mark;
        vector<int> pred;
        int numV;
        int numEdge;
    
    public:
        Graphs(int n){
            lista.resize(n);
            mark.assign(n, 0);
            pred.assign(n,-1);
            numEdge=0;
            numV=n;
 
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
 
         void setEdge( int i, int j){
            lista[i].push_back(j);
            lista[j].push_back(i);
            numEdge++;
            
         }
 
        void setMark( int v, int x){
            mark[v]=x;
        }
        int getMark(int v){
            return mark[v];
        }
 
        void setPred(int x,int w){
            pred[w]=x;
        }
 
        int getPred(int v){
            return pred[v];
        }
 
        /*void transverse(int v){
            for (int i=0; i<numV;i++){
                setMark(i,0);
            }
            for(int i=0; i<numV; i++){
                if(getMark(i)==0){
                    //BFS(i,);
                }
            }
        }*/
 
         void transverse1(int i, int j){
            for (int i=0; i<numV;i++){
                setMark(i,0);
            }
            BFS(i,j);
                
            
        }
 
        void previsit(int v){
            cout<<v<<" ";
        }
 
        void BFS(int v, int final){
            queue<int> Q;
            Q.push(v);
            setMark(v,1);
            while(Q.size()>0){
                int x=Q.front();
                Q.pop();
                //previsit(x);
                int w=first(x);
                while(w<numV){
                    if(getMark(w)==0){
                        setMark(w,1);
                        Q.push(w);///// apartir do moment qm que coloco ele na fila bot o antecessor
                        setPred(w,x);
                    }
                    w=next(x,w);
                }
            }
        }
 
        stack<int> lerCaminho(int x,int y){
            /// botR NUM atCK pra pintar ao contrário
            stack<int> caminho;
            if(!mark[y]){return caminho;}// náo tem caminho


            caminho.push(y);
            int meio=getPred(y);

            if(X==Y){return caminho;}

            while(meio!=x && meio!= -1){// sem predecessor
                caminho.push(meio);
                meio=getPred(meio);
            }
            if(meio==x){caminho.push(x);}

            return caminho
        }
 
};
 



/////////// colocar na main depos que chamar a funcao pa ler o caminho
while(!caminho.empty()){
                cout<<caminho.top()<<" ";
                caminho.pop();
            }
            cout<<endl;
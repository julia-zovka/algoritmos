#include <iostream>
#include<vector>
#include <queue>
#include <stack>
using namespace std;


///////// BSFFF

//////// SE TIVER MARCODO NO MARK PRINTA NA MATRIZ NO FINAL
 
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
            for (int v : lista[i]) {
                if (v == j) return; // já existe, não adiciona de novo
            }
            lista[i].push_back(j);
            numEdge++;
        }
        void setMark( int v, int x){
            mark[v]=x;
        }
        int getMark(int v){
            return mark[v];
        }
 
        void setPred(int w,int x){
            pred[w]=x;
        }
 
        int getPred(int v){
            return pred[v];
        }
 
    
         void transverse1(int i){
            for (int i=0; i<numV;i++){
                setMark(i,0);
            }
            BFS(i);
        }
 
        void BFS(int v){
            queue<int> Q;
            Q.push(v);
            setMark(v,1);
            while(Q.size()>0){
                int x=Q.front();
                Q.pop();
                int w=first(x);
                while(w<numV){
                    if(getMark(w)==0){
                        setMark(w,1);
                        Q.push(w);
                        setPred(w,x);///// apartir do moment qm que coloco ele na fila bot o antecessor
                    }
                    w=next(x,w);
                }
            }
        }
 
        void lerCaminho(int x,int y, int n, int m, vector<vector<char>> &matrix ){
            /// botR NUM atCK pra pintar ao contrário
            stack<int> caminho;
            if(!mark[y]){cout<<-1<<endl;
            return;}// náo tem caminho

            caminho.push(y);
            int meio=getPred(y);
            while(meio!=x && meio!= -1){// sem predecessor
                caminho.push(meio);
                meio=getPred(meio);
            }
            if(meio==x){caminho.push(x);}
            
            //// ver os elementos de caminho e traduzir os id na matrix original da entrada
            while(!caminho.empty()){
                int x=caminho.top();
                caminho.pop();
                int i=x / m;
                int j=x % m;
                matrix[i][j]='X';
            }
            for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                    cout<<matrix[i][j];
                }
                cout<<endl;
            }
        }
};
 
int main(){
    int m, n, vertices;
    cin>>n;
    cin>>m;
    vertices=n*m;
    Graphs grafo(vertices);

    //// pra guarda a entrada com . ou >><<<
    vector<vector<char>> matrix;
    matrix.assign(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];  
        }
    }

    /// tirar a possibilidade de  arestas do grafo caso os guardinhas esstejam nessa direcao
    vector<vector<bool>> proibido;
    proibido.assign(n,vector<bool>(m, false));///come;a podendo em todas as posicao do grid

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (matrix[i][j]=='>'|| matrix[i][j]=='<' || matrix[i][j]=='^' || matrix[i][j]=='v') {proibido[i][j] = true;

                if(matrix[i][j]=='>'){
                    int k=j+1;
                    bool continuar=true;
                    while(continuar && k<m){
                        if (matrix[i][k] != '.') {continuar=false;}// encontrou outro guardinha
                        else{proibido[i][k] = true;
                            k++;}// so posi;oes livres que agora ficam proibidas
                    }
                }
                else if(matrix[i][j]=='<'){
                    int k=j-1;
                    bool continuar=true;
                    while(continuar && k>=0){
                        if (matrix[i][k] != '.') {continuar=false;}// encontrou outro guardinha
                        else{proibido[i][k] = true;
                            k--;}// so posi;oes livres que agora ficam proibidas
                    }
                }
                else if(matrix[i][j]=='^'){
                    int k=i-1;
                    bool continuar=true;
                    while(continuar && k>=0){
                        if (matrix[k][j] != '.') {continuar=false;}// encontrou outro guardinha
                        else{proibido[k][j] = true;
                            k--;}// so posi;oes livres que agora ficam proibidas
                    }
                }
                else if(matrix[i][j]=='v'){
                    int k=i+1;
                    bool continuar=true;
                    while(continuar && k<n){
                        if (matrix[k][j] != '.') {continuar=false;}// encontrou outro guardinha
                        else{proibido[k][j] = true;
                            k++;}// so posi;oes livres que agora ficam proibidas
                    }
                }
            }
        }
    }
    ///// criar as arestas do grafo
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(proibido[i][j]==false){
                int atual=i*m+j;// numero do vertice autal
                //olhando pa cima
                if( i>0 && proibido[i-1][j]==false){
                    int cima=(i-1)*m+j;
                    grafo.setEdge(atual,cima );
                    //grafo.setEdge(cima, atual);
                }
                //olhando pra baixo
                if( i<n-1 && proibido[i+1][j]==false){
                    int baixo=(i+1)*m+j;
                    grafo.setEdge(atual,baixo );
                    //grafo.setEdge(baixo, atual);
                }
                //esq
                if( j>0 && proibido[i][j-1]==false){
                    int esquerda=i*m+(j-1);
                    grafo.setEdge(atual, esquerda);
                    //grafo.setEdge(esquerda, atual);
                }
                //dir
                if(j<m-1 && proibido[i][j+1]==false){
                    int direita=i*m+(j+1);
                    grafo.setEdge(atual, direita);
                   // grafo.setEdge(direita, atual);

                }
            }
        }
    }

    //chamr bsf
    if (proibido[0][0] || proibido[n-1][m-1]) {
        cout << -1 << endl;
        return 0;
    }
    grafo.transverse1(0);
    int final_id = (n-1)*m+(m-1);
    grafo.lerCaminho(0,final_id,n,m,matrix);
}

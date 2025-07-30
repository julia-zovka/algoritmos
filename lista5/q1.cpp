//backtracking - uma unica solucao possívl para a entrada



/*def backtrack(solution, step):
    if is_solution(solution, step):
        process_solution(solution)
        return
    
    for choice in possible_choices(solution, step):
        if is_valid(choice):
            make_choice(solution, step, choice)
            backtrack(solution, step + 1)
            unmake_choice(solution, step, choice)  # Backtrack
*/

#include <iostream>
#include <vector>
#include <algorithm> // pra search
using namespace std;

bool valid(int num,int i, int j, vector<vector<int>> &matriz){

    int starcol;
    int startrow;

    for(int x=0;x<9;x++){// checa na linha
        if (matriz[i][x]==num){
        return false;}
    }

    for(int x=0;x<9;x++){//checa coluna
        if (matriz[x][j]==num){
            return false;
        }
    }

    if(i==0 || i==1 || i==2){//define o grid
        startrow=0;
        if(j==0 || j==1|| j==2){
            starcol=0;
        }
        else if (j==3 || j==4 || j==5){
            starcol=3;
        }
        else{starcol=6;}
    }

    else if(i==3 ||i==4 ||i==5){
        startrow=3;
        if(j==0 || j==1|| j==2){
            starcol=0;
        }
        else if (j==3 || j==4 || j==5){
            starcol=3;
        }
        else{starcol=6;}
    }
    else{ 
        startrow=6;
        if(j==0 || j==1|| j==2){
            starcol=0;
        }
        else if (j==3 || j==4 || j==5){
            starcol=3;
        }
        else{starcol=6;}
    }

    for(int x=0;x<3;x++){///// checa se tem no grid
        for(int y=0;y<3;y++){
            if (matriz[startrow+x][starcol+y]==num){
                return false;
            }
        }
    }

    return true;  // Number is valid  naquela position
}


bool sudoku(int i,int j, vector<vector<int>> &matriz ){
    if (i==9){return true;}/// x vai marcar em qual linha estamos

    if(j==9){//final da linha mas ainda tem outras linhas pra processar
    i++;
    j=0;
    return sudoku(i,j,matriz);}

    if(matriz[i][j]!=0){//não pode mudar essa casa, vai pra proxima
        return sudoku(i,j+1, matriz);
    }
    else{// é 0
        for (int num=1;num<=9;num++){
            if (valid(num, i, j, matriz)){

                matriz[i][j]=num;/// coloco o numeor 1, ou 2 ou 3 na posicao da matriz
                if (sudoku(i,j+1, matriz)){return true;}// retorna true quando achar un caso que de certo e não fica exausto
                else{matriz[i][j]=0;}
            }
        }
        return false;//se não colocou o numero em nenhuma coluna daquela linha 
    }
}
int main(){
    vector<vector<int>> matriz(9, vector<int>(9));
    int query,num;
    cin>>query;
    for(int r=0;r<query;r++){
        //populando
        for (int b=0;b<9;b++){
            for (int i=0;i<9;i++){
                cin>>num;
                matriz[b][i]=num;
            }
        }

        if(sudoku(0,0,matriz)){
            for(int x=0;x<9;x++){
                for(int num: matriz[x]){
                    cout<<num<<" ";/// first e next de v
                }
                cout<<endl;
            }
        }
        else{
            cout<<"No solution"<<endl;
        }
    }
}
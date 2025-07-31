#include <vector>
#include <iostream>
using namespace std;

//vou ter que considerar o caso de que o tesou pode ta pra cima pra baiso e para os dois lados da entradaaaa
//considerar casos de looppp


bool mazee(int i, int j, int lives, vector<vector<char>> &maze, int wid,int hght, int spikes, vector<vector<bool>> &visited){

    if(j>=wid || j<0 || i<0|| i>=hght){// ja foi pra pa fora da maze
        return false;
    }
    if (maze[i][j]=='x' && lives>=spikes*2 ){ return true;}/// chegu onde queriaa sem morrer e consegue voltar

    if(maze[i][j]=='#'){return false;}// nao posso naquele 

    else{// se não é parede pode testar// se náo [arede  . =andar ou s=menos vida ou x=cehoug
        if(visited[i][j]==true){return false;}//loop

        else{//quando ainda t[a ] false==primeira vez que passou pelo lugar na tentativa de ida
            visited[i][j]=true;
        }

        if(maze[i][j]=='s'){//tem spike mas pde tentar  vai por ali
            if(lives==0){return false;}//moreuuu
            else{
                spikes++;}
        }
        //tenta todas as direc;oes
        if(mazee(i-1,j, lives, maze, wid, hght,spikes,visited)){return true;}
        if(mazee(i+1,j, lives, maze, wid, hght,spikes,visited)){return true;}
        if(mazee(i,j-1, lives, maze, wid, hght,spikes,visited)){return true;}
        if(mazee(i,j+1, lives, maze, wid, hght,spikes,visited)){return true;}
        //nenhuma resultou em caminho
        visited[i][j]=false;
        return false;
        
    }
}

int main(){
    int rows,w,lives, spikes, co_i,co_j;
    char c;
    spikes=0;
    cin>>rows>>w>>lives;
    vector<vector<char>> maze(rows);//// ###    ...   @@@   SSS  XXX
    vector<vector<bool>> visited(rows,vector<bool> (w,false));

    //popular cada linha da maze
    for(int i=0;i<rows;i++){
        for(int y=0;y<w;y++){
            cin>>c;
            if (c=='s'){
            }
            if(c=='@'){
                co_i=i;
                co_j=y;
            }
            maze[i].push_back(c);
        }
    }
    if(mazee(co_i,co_j,lives,maze, w, rows, spikes,visited)){
        cout<<"SUCCESS"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}
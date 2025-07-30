/*The first line of a test case contains three integers n, m and j.
 n (2 ≤ n ≤ 40) the number of rows, m (2 ≤ n ≤ 40) the width of each row and j (0 ≤ j ≤ 20)
  the number of times Jarmtin can avoid spikes. Then n lines containing m characters; 
  The character 'x' will be used for the place of the treasure, '@' for an entrance (which is also an exit), '#' for walls, '.' for a safe walking tile and 's' for spikes. Note that you cannot walk into walls and the maze is completely surrounded by walls outside what you can see. 
\There is always at least one entrance/exit and always an x where the treasure is.*/

#include <vector>
#include <iostream>

using namespace std;






bool mazee(int i, int j, int lives, vector<vector<char>> &maze, int wid,int hght, int spikes ){
    if (maze[i][j]=='x' && lives>=spikes/2) return true;/// chegu onde queriaa sem morrer e consegue voltar

    if(j==wid){//fim da linha entao desce pra proxima
        return mazee(i+1,0,lives,maze,wid,hght,spikes);
    }
    

    if(maze[i][j]!='#'){// se não é parede pode testar

        if(maze[i][j]=='s' && lives!=0){//tem spike mas ainda tem vida,  vai por ali
            lives--;
            mazee(i,j+1, lives, maze, wid, hght,spikes);
        }
        if(maze[i][j]=='.'){
            mazee(i,j+1, lives, maze, wid, hght,spikes);
        }

    }

}
int main(){
    int rows,w,lives, spikes;
    char c;
    cin>>rows>>w>>lives;
    vector<vector<char>> maze(rows);//// ###    ...   @@@   SSS  XXX

    //popular cada linha da maze
    for(int i=0;i<rows;i++){
        cin>>c;
        if (c=='s'){
            spikes++;
        }
        maze[i].push_back(c);
    }

    //comecar a passear pela maze // come;ar backtracking

}
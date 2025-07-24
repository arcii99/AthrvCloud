//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#define ROW 5
#define COL 5
 
int maze[ROW][COL] = {
                    {1, 0, 1, 1, 1},
                    {1, 1, 1, 0, 1},
                    {0, 0, 1, 1, 1},
                    {0, 0, 0, 1, 0},
                    {1, 1, 1, 1, 1}
                   };
 
int sol[ROW][COL];
 
int isSafe(int x, int y){
    if(x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==1)
        return 1;//true
    return 0;//false
}
 
int solveMazeUtil(int x, int y){
    if(x==ROW-1 && y==COL-1){//If reached destination
        sol[x][y] = 1;
        return 1;
    }
    if(isSafe(x,y)==1){
        sol[x][y] = 1;//marking visited
        if(solveMazeUtil(x+1, y))//Check bottom
            return 1;
        if(solveMazeUtil(x, y+1)) //Check right
            return 1;
        sol[x][y] = 0;//If none of the above moves work, backtrack
        return 0;
    }
    return 0;//false
}
 
void solveMaze(){
    if(solveMazeUtil(0,0)==0){//if no path exits
        printf("No solution\n");
        return;
    }
    printf("Path exists: [");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf(" %d ", sol[i][j]);
        }
        if(i!=ROW-1)//separator
            printf("\n           ");
    }
    printf("]\n");
}
 
int main(){
    solveMaze();
    return 0;
}
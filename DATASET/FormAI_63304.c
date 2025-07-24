//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include<stdio.h>
#define N 5

void displayPath(int path[][N]){
    int i,j;
    for(i = 0; i<5; i++){
        for(j = 0; j<5; j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

/* check whether there is path at row, col */
int isPath(int x, int y, int maze[][N]){
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return 1;
    return 0;
}

/* solve the maze recursively */
int solveMazeUtil(int maze[][N], int x, int y, int path[][N]){
    if(x == N-1 && y == N-1 && maze[x][y] == 1){
        path[x][y] = 1;
        return 1;
    }
    if(isPath(x,y,maze)==1){
        path[x][y] = 1;

        if(solveMazeUtil(maze,x+1,y,path)==1)
            return 1;

        if(solveMazeUtil(maze,x,y+1,path)==1)
            return 1;

        path[x][y] = 0;
        return 0;
    }
    return 0;
}

/* solveMaze function*/
void solveMaze(int maze[][N]){
    int path[N][N] = {{0}};
    if (solveMazeUtil(maze, 0, 0, path) == 0)
    {
        printf("Solution doesn't exist!\n");
        return;
    }
    printf("Path Found!\n");
    displayPath(path);
}

/* main function */
int main()
{
    int maze[N][N]  =  { { 1, 0, 0, 0, 0 },
                         { 1, 1, 1, 1, 0 },
                         { 0, 1, 0, 1, 0 },
                         { 1, 1, 0, 1, 1 },
                         { 0, 1, 0, 0, 1 } };

    solveMaze(maze);
    return 0;
}
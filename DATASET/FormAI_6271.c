//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void dfs(int maze[][COLS], int x, int y){
    int i, j;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int dir[] = {0, 1, 2, 3};
    int k = 0, tmp, r;

    for(i = 0; i < 4; i++){
        r = rand()%4;
        tmp = dir[i];
        dir[i] = dir[r];
        dir[r] = tmp;
    }

    maze[x][y] = 0;

    for(i = 0; i < 4; i++){
        k = dir[i];
        if(x+dx[k]>=0 && x+dx[k]<COLS && y+dy[k]>=0 && y+dy[k]<ROWS){
            if(maze[x+dx[k]][y+dy[k]] == 1){
                if(k==0)
                    maze[x][y] |= 1; //top
                if(k==1)
                    maze[x][y] |= 2; //bottom
                if(k==2)
                    maze[x][y] |= 4; //left
                if(k==3)
                    maze[x][y] |= 8; //right
                dfs(maze, x+dx[k], y+dy[k]);
            }
        }
    }
}

void print_maze(int maze[][COLS], int rows, int cols){
    int i,j;

    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("+");
            if(maze[i][j]&1)
                printf("---");
            else
                printf("   ");
        }
        printf("+\n");
        for(j=0;j<cols;j++){
            if(maze[i][j]&4)
                printf("|   ");
            else
                printf("    ");
        }
        if(maze[i][cols-1]&8)
            printf("|");
        else
            printf(" ");
        putchar('\n');
    }
    for(i=0;i<cols;i++)
        printf("+-+");
    putchar('\n');
}

int main(){
    srand(time(NULL));

    int maze[ROWS][COLS];
    int start_x = rand()%COLS;
    int start_y = rand()%ROWS;

    int i,j;
    for(i=0;i<ROWS;i++)
        for(j=0;j<COLS;j++)
            maze[i][j] = 1;

    dfs(maze, start_x, start_y);

    print_maze(maze, ROWS, COLS);

    return 0;
}
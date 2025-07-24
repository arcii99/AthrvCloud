//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
                        {1,0,1,1,1,0,1,1,1,1},
                        {1,0,1,0,1,0,1,0,1,0},
                        {1,1,1,0,1,0,1,0,1,0},
                        {0,0,0,0,1,1,1,0,1,1},
                        {1,1,1,0,0,0,1,0,0,1},
                        {0,0,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0,0,1},
                        {0,1,1,1,1,1,1,1,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1}
                    };

int valid_move(int x, int y){
        if(x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==1)
                return 1;
        return 0;
}

void print_solution(int sol[ROW][COL]){
        int i,j;
        printf("The solution for the given maze is:\n");
        for(i=0;i<ROW;i++){
                for(j=0;j<COL;j++)
                        printf("%d ", sol[i][j]);
                printf("\n");
        }
}

int maze_solver(int x, int y, int sol[ROW][COL]){
        if(x==ROW-1 && y==COL-1){
                sol[x][y] = 1;
                return 1;
        }

        if(valid_move(x,y)==1){
                sol[x][y] = 1;
                if(maze_solver(x+1, y, sol)==1)
                        return 1;
                if(maze_solver(x, y+1, sol)==1)
                        return 1;
                sol[x][y] = 0;
                return 0;
        }
        return 0;
}

int main(){
        int sol[ROW][COL];
        int i,j;
        for(i=0;i<ROW;i++)
                for(j=0;j<COL;j++)
                        sol[i][j] = 0;

        if(maze_solver(0,0,sol)==1)
                print_solution(sol);
        else
                printf("No solution exists for the given maze!");

        return 0;
}
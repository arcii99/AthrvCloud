//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11

void new_maze(int maze[ROW][COL]){
    // This function generates a new random maze
    srand(time(NULL));
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            maze[i][j] = rand()%2;
        }
    }
    maze[0][1] = 1;
    maze[ROW-1][COL-2] = 1;
}

void print_maze(int maze[ROW][COL]){
    // This function prints the maze
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(maze[i][j] == 0){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    int maze[ROW][COL];
    new_maze(maze);
    
    print_maze(maze);
    
    return 0;
}
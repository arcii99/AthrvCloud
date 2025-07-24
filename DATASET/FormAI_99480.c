//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
int visited[ROWS][COLS];
int sr,sc; // starting row and column
int er,ec; // end row and column

// function to print the maze to the console
void print_maze(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

// function to initialize the maze
void init_maze(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            maze[i][j] = rand()%2;
            visited[i][j] = 0;
        }
    }
    // set the start and end points
    sr = rand()%ROWS;
    sc = rand()%COLS;
    do{
        er = rand()%ROWS;
        ec = rand()%COLS;
    }while(sr == er && sc == ec);
    maze[sr][sc] = 2;
    maze[er][ec] = 3;
}

// recursive function to find a path through the maze
int find_path(int r,int c){
    visited[r][c] = 1;
    if(r == er && c == ec){
        return 1;
    }
    if(r > 0 && maze[r-1][c] && !visited[r-1][c] && find_path(r-1,c)){
        return 1;
    }
    if(c > 0 && maze[r][c-1] && !visited[r][c-1] && find_path(r,c-1)){
        return 1;
    }
    if(r < ROWS-1 && maze[r+1][c] && !visited[r+1][c] && find_path(r+1,c)){
        return 1;
    }
    if(c < COLS-1 && maze[r][c+1] && !visited[r][c+1] && find_path(r,c+1)){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    init_maze();
    print_maze();
    printf("\n");
    if(find_path(sr,sc)){
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(maze[i][j] == 2){
                    printf("S ");
                }else if(maze[i][j] == 3){
                    printf("E ");
                }else{
                    printf("%d ",visited[i][j]);
                }
            }
            printf("\n");
        }
    }else{
        printf("No path found.\n");
    }
    return 0;
}
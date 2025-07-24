//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

// Function to randomly generate the maze
void generate_maze()
{
    srand(time(NULL)); // Setting seed for random function
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            maze[i][j]=rand() % 2;
        }
    }
}

// Function to print the maze
void print_maze()
{
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the maze with walls 
void initialize_maze()
{
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1) maze[i][j]=0;
            else maze[i][j]=1;
        }
    }
}

// Function to modify the maze with paths 
void modify_maze()
{
    int i, j;
    for(i=1;i<ROWS-1;i++){
        for(j=1;j<COLS-1;j++){
            if(maze[i-1][j]==0 && maze[i+1][j]==0 && maze[i][j-1]==0 && maze[i][j+1]==0 && maze[i][j]==1){
                int rand_num=rand()%4;
                if(rand_num==0) maze[i-1][j]=2;
                if(rand_num==1) maze[i+1][j]=2;
                if(rand_num==2) maze[i][j-1]=2;
                if(rand_num==3) maze[i][j+1]=2;
            }
        }
    }

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(maze[i][j]==2) maze[i][j]=1;
        }
    }
}

// Function to check whether the maze is complete or not
int maze_complete()
{
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(maze[i][j]==1) return 0;
        }
    }
    return 1;
}

int main()
{
    initialize_maze();
    generate_maze();
    while(!maze_complete()){
        modify_maze();
    }
    print_maze();
    return 0;
}
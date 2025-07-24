//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int maze[SIZE][SIZE]; //2D maze

void generate_maze(){ //function to generate maze
    srand(time(NULL)); //seed for random number generator
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(i==0 || i==SIZE-1 || j==0 || j==SIZE-1) //border walls
                maze[i][j] = 1; //set as wall
            else if(rand()%2) //random probability of wall or path
                maze[i][j] = 1; //set as wall
            else
                maze[i][j] = 0; //set as path
        }
    }
}

void print_maze(){ //function to print the maze
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(maze[i][j] == 1)
                printf("X ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main(){
    generate_maze();
    print_maze();
    return 0;
}
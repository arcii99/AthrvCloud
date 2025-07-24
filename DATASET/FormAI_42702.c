//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20
#define WALL 0
#define PATH 1

void print_maze(int maze[][MAZE_SIZE]){
    for(int row=0; row<MAZE_SIZE; row++){
        for(int col=0; col<MAZE_SIZE; col++){
            if(maze[row][col] == WALL){
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int maze[][MAZE_SIZE], int row, int col){

    int directions[4][2] = {
        {-2,0},    // UP
        {0,2},     // RIGHT
        {2,0},     // DOWN
        {0,-2}     // LEFT
    };


    // Shuffle the direction array using Fisher-Yates algorithm
    for(int i=3; i>0; i--){
        int j = rand() % (i+1);
        int temp[2] = {directions[i][0], directions[i][1]};
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp[0];
        directions[j][1] = temp[1];
    }

    // Carve out the paths
    for(int i=0; i<4; i++){
        int next_row = row + directions[i][0];
        int next_col = col + directions[i][1];
        int in_between_row = (row + next_row) / 2;
        int in_between_col = (col + next_col) / 2;

        if(next_row < 0 || next_row >= MAZE_SIZE || next_col < 0 || next_col >= MAZE_SIZE){
            continue;
        }

        if(maze[next_row][next_col] == WALL){
            maze[in_between_row][in_between_col] = PATH;
            maze[next_row][next_col] = PATH;

            generate_maze(maze, next_row, next_col);
        }
    }
}

int main(){
    int maze[MAZE_SIZE][MAZE_SIZE] = {0};

    // Seed the random number generator
    srand(time(NULL)); 

    // Generate maze starting at row 1, col 1 (odd integers)
    generate_maze(maze, 1, 1);

    // Print maze
    print_maze(maze);

    return 0;
}
//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

void generateMaze(int maze[ROWS][COLS], int row, int col);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL)); // seed random number generator
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[ROWS][COLS], int row, int col) {
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // Possible directions to move in
    int random_dir, new_row, new_col;
    int i, j, cnt;

    cnt = 0;
    maze[row][col] = 0;

    while(cnt < 4){
        random_dir = rand() % 4; // Get a random direction to move in
        new_row = row + directions[random_dir][0];
        new_col = col + directions[random_dir][1];
        
        // Check if new location is within the maze
        if(new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS){
            // Check if new location is not already visited
            if(maze[new_row][new_col] != 0){
                // Create path to new location
                if(random_dir == 0) { // move right
                    maze[row][col] |= 1;
                    maze[new_row][new_col] |= 4;
                } else if(random_dir == 1) { // move left
                    maze[row][col] |= 4;
                    maze[new_row][new_col] |= 1;
                } else if(random_dir == 2) { // move down
                    maze[row][col] |= 2;
                    maze[new_row][new_col] |= 8;
                } else if(random_dir == 3) { // move up
                    maze[row][col] |= 8;
                    maze[new_row][new_col] |= 2;
                }
                generateMaze(maze, new_row, new_col); // Recurse with new location
            } else{
                cnt++;
            }
        } else{
            cnt++;
        }
    }
}

void printMaze(int maze[ROWS][COLS]){
    int i, j;
    printf(" ");
    for(i = 0; i < COLS*2; i++)
        printf("_");
    printf("\n");
    for(i = 0; i < ROWS; i++){
        printf("|");
        for(j = 0; j < COLS; j++){
            if((maze[i][j] & 4) == 0)
                printf(" ");
            else
                printf("_");

            if((maze[i][j] & 2) == 0)
                printf(" ");
            else
                printf("|");
        }
        printf("\n");
    }
}
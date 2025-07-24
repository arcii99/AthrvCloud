//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void printMaze(char maze[ROWS][COLS]);

int main(){
    srand(time(NULL)); // Set random seed
    
    char maze[ROWS][COLS];
    
    // Fill maze with walls and empty spaces randomly
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1){
                maze[i][j] = '#'; // add walls to borders
            }else if(rand() % 3 == 0){
                maze[i][j] = '#'; // add walls randomly
            }else{
                maze[i][j] = '.'; // empty space
            }
        }
    }
    
    // Start at top left corner and make pathway
    int r = 1;
    int c = 1;
    maze[r][c] = '.';
    
    // Keep moving until bottom right corner is reached
    while(r != ROWS-2 || c != COLS-2){
        int direction = rand() % 4; // 0 = up, 1 = right, 2 = down, 3 = left
        
        // Check if chosen direction is valid and move there
        if(direction == 0 && maze[r-1][c] == '#'){ // up
            maze[r-1][c] = '.';
            r--;
        }else if(direction == 1 && maze[r][c+1] == '#'){ // right
            maze[r][c+1] = '.';
            c++;
        }else if(direction == 2 && maze[r+1][c] == '#'){ // down
            maze[r+1][c] = '.';
            r++;
        }else if(direction == 3 && maze[r][c-1] == '#'){ // left
            maze[r][c-1] = '.';
            c--;
        }
    }
    
    printMaze(maze);
    
    return 0;
}

void printMaze(char maze[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
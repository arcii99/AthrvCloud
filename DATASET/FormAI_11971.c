//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 21
#define COL 47

void printMaze(char maze[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROW][COL]){
    srand(time(NULL)); // initialize random seed
    
    // Set all maze cells to walls
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            maze[i][j] = '#';
        }
    }
    
    // Set the starting point and mark it as open
    int startRow = 1;
    int startCol = 1;
    maze[startRow][startCol] = ' ';
    
    // Initialize variables for current location and directions
    int currentRow = startRow;
    int currentCol = startCol;
    int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // South, East, North, West
    
    // Loop to carve out the maze
    while(1){
        int hasOpenings = 0;
        for (int i=0; i<4; i++){
            int r = rand() % 4;
            int nextRow = currentRow + directions[r][0]*2;
            int nextCol = currentCol + directions[r][1]*2;
            int betweenRow = currentRow + directions[r][0];
            int betweenCol = currentCol + directions[r][1];
          
            if(nextRow >= ROW || nextRow < 0 || nextCol >= COL || nextCol < 0 || maze[nextRow][nextCol] != '#' || betweenRow >= ROW || betweenRow < 0 || betweenCol >= COL || betweenCol < 0 || maze[betweenRow][betweenCol] != '#'){
                continue;
            }
            else{
                hasOpenings=1;
                maze[betweenRow][betweenCol] = ' ';
                maze[nextRow][nextCol] = ' ';
                currentRow = nextRow;
                currentCol = nextCol;
                break;
            }
        }
        if(hasOpenings==0){
            break;
        }
    }
    // Set the end point and mark it as open
    int endRow = ROW-2;
    int endCol = COL-2;
    maze[endRow][endCol] = ' ';
}

int main(){
    char maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}
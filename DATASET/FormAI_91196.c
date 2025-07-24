//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[ROWS][COLS])
{
    srand((unsigned) time(NULL)); // seed random generator with current time

    // set maze cells as all walls (0 = wall)
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            maze[row][col] = 0;
        }
    }

    // generate random starting point
    int row = rand() % ROWS;
    int col = rand() % COLS;
    maze[row][col] = 1; // mark starting cell as open (1 = open)

    // create a list of unvisited cells
    int unvisitedCount = (ROWS * COLS) - 1; // subtract starting cell
    int unvisited[unvisitedCount][2];
    int index = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) { // unvisited cell
                unvisited[index][0] = i;
                unvisited[index][1] = j;
                index++;
            }
        }
    }

    while(unvisitedCount > 0) {
        // choose a random unvisited neighbor of the current cell
        int neighbors[4][2];
        int neighborCount = 0;
        if(row - 1 >= 0 && maze[row-1][col] == 0) {
            neighbors[neighborCount][0] = row - 1;
            neighbors[neighborCount][1] = col;
            neighborCount++;
        }
        if(row + 1 < ROWS && maze[row+1][col] == 0) {
            neighbors[neighborCount][0] = row + 1;
            neighbors[neighborCount][1] = col;
            neighborCount++;
        }
        if(col - 1 >= 0 && maze[row][col-1] == 0) {
            neighbors[neighborCount][0] = row;
            neighbors[neighborCount][1] = col - 1;
            neighborCount++;
        }
        if(col + 1 < COLS && maze[row][col+1] == 0) {
            neighbors[neighborCount][0] = row;
            neighbors[neighborCount][1] = col + 1;
            neighborCount++;
        }

        if(neighborCount > 0) {
            int chosen = rand() % neighborCount;
            int chosenRow = neighbors[chosen][0];
            int chosenCol = neighbors[chosen][1];
            maze[chosenRow][chosenCol] = 1; // open new cell
            row = chosenRow;
            col = chosenCol;
            // remove new cell from unvisited list
            for(int i = 0; i < unvisitedCount; i++) {
                if(unvisited[i][0] == chosenRow && unvisited[i][1] == chosenCol) {
                    unvisitedCount--;
                    unvisited[i][0] = unvisited[unvisitedCount][0];
                    unvisited[i][1] = unvisited[unvisitedCount][1];
                }
            }
        } else {
            // backtrack to last unvisited cell
            for(int i = unvisitedCount-1; i >= 0; i--) {
                int r = unvisited[i][0];
                int c = unvisited[i][1];
                if((r == row-1 && c == col) || (r == row+1 && c == col) ||
                   (r == row && c == col-1) || (r == row && c == col+1)) {
                    row = r;
                    col = c;
                    break;
                }
            }
        }
    }
}

void printMaze(int maze[ROWS][COLS])
{
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(maze[row][col] == 0) {
                printf("█"); // wall
            } else {
                printf(" "); // open
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}
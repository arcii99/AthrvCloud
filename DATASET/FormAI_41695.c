//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //change size of the grid as per your preference
#define PERC_THRESHOLD 70 //change the threshold for percolation as per your preference

int grid[SIZE][SIZE]; //grid for percolation simulation

//function to initialize the grid
void initialize() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(rand()%100 < PERC_THRESHOLD) {
                grid[i][j] = 1; //cell filled with water
            }
            else {
                grid[i][j] = 0; //cell empty
            }
        }
    }
}

//function to print the grid
void printGrid() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("W "); //cell with water
            }
            else {
                printf(". "); //empty cell
            }
        }
        printf("\n");
    }
}

//function to check if percolation has occurred
int isPercolated() {
    int i, j;
    for(j = 0; j < SIZE; j++) {
        if(grid[0][j] == 1) { //check if first row cell is filled with water
            int visited[SIZE][SIZE] = {0}; //create a visited array
            visited[0][j] = 1; //mark the first row cell as visited
            int stack[SIZE * SIZE][2];
            int top = -1;
            top++;
            stack[top][0] = 0; //push row value
            stack[top][1] = j; //push column value
            
            //perform DFS on the neighbouring water cells to look for a path to the last row
            while(top != -1) {
                int r = stack[top][0];
                int c = stack[top][1];
                top--;
                if(r == SIZE - 1) {
                    return 1; //last row reached, percolation occurred
                    
                }
                if(r - 1 >= 0 && grid[r-1][c] == 1 && visited[r-1][c] == 0) {
                    top++;
                    stack[top][0] = r-1;
                    stack[top][1] = c;
                    visited[r-1][c] = 1;
                }
                if(r + 1 < SIZE && grid[r+1][c] == 1 && visited[r+1][c] == 0) {
                    top++;
                    stack[top][0] = r+1;
                    stack[top][1] = c;
                    visited[r+1][c] = 1;
                }
                if(c - 1 >= 0 && grid[r][c-1] == 1 && visited[r][c-1] == 0) {
                    top++;
                    stack[top][0] = r;
                    stack[top][1] = c-1;
                    visited[r][c-1] = 1;
                }
                if(c + 1 < SIZE && grid[r][c+1] == 1 && visited[r][c+1] == 0) {
                    top++;
                    stack[top][0] = r;
                    stack[top][1] = c+1;
                    visited[r][c+1] = 1;
                }
            }
        }
    }
    return 0; //last row not reached, percolation not occurred
}

int main() {
    initialize();
    printf("Initial Grid:\n");
    printGrid();
    if(isPercolated()) {
        printf("\nPercolation occurred!\n");
    }
    else {
        printf("\nPercolation did not occur.\n");
    }
    return 0;
}
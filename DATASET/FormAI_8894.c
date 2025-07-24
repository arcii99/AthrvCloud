//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //Size of grid
#define PERC_THRESHOLD 0.5 //Percolation threshold

void print_grid(int grid[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolates(int grid[][SIZE]) {
    //Create visited array
    int visited[SIZE][SIZE] = {0};
    
    //Mark first row as visited
    for(int i=0; i<SIZE; i++) {
        if(grid[0][i] == 1) {
            visited[0][i] = 1;
        }
    }
    
    //Visit all connected cells
    int stack[SIZE*SIZE][2];
    int top = -1;
    for(int i=0; i<SIZE; i++) {
        if(grid[0][i] == 1) {
            stack[++top][0] = 0;
            stack[top][1] = i;
        }
    }
    
    while(top >= 0) {
        int i = stack[top][0];
        int j = stack[top][1];
        top--;
        
        if(i+1 < SIZE && grid[i+1][j] == 1 && !visited[i+1][j]) {
            visited[i+1][j] = 1;
            stack[++top][0] = i+1;
            stack[top][1] = j;
        }
        if(i-1 >= 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
            visited[i-1][j] = 1;
            stack[++top][0] = i-1;
            stack[top][1] = j;
        }
        if(j+1 < SIZE && grid[i][j+1] == 1 && !visited[i][j+1]) {
            visited[i][j+1] = 1;
            stack[++top][0] = i;
            stack[top][1] = j+1;
        }
        if(j-1 >= 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
            visited[i][j-1] = 1;
            stack[++top][0] = i;
            stack[top][1] = j-1;
        }
    }
    
    //Check if last row is visited
    for(int i=0; i<SIZE; i++) {
        if(visited[SIZE-1][i]) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    srand(time(0));
    
    int grid[SIZE][SIZE] = {0};
    
    //Add random cells to grid
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            float r = (float)rand()/(float)RAND_MAX;
            if(r < PERC_THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }
    
    print_grid(grid);
    
    if(percolates(grid)) {
        printf("Grid percolates.\n");
    } else {
        printf("Grid does not percolate.\n");
    }
    
    return 0;
}
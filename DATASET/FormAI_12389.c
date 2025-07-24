//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 10
#define COLS 10

void print_grid(int grid[][COLS], int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<COLS; j++){
            if(grid[i][j] == -1){
                printf(" X ");
            } else {
                printf(" %d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int grid[ROWS][COLS];
    memset(grid, 0, sizeof(grid));

    // Set starting position
    int row = 0, col = 0; 
    int move_num = 1;
    int dir = +1; // +1 for forward, -1 for backwards

    while(row >= 0 && row < ROWS && col >=0 && col < COLS){
        grid[row][col] = move_num++;

        // Check if we need to reverse direction
        if(grid[row][col] % 11 == 0){
            dir = -dir;
        }

        // Move forward or backwards based on direction
        if(col + dir >= COLS){
            row++;
        } else if (col + dir < 0) {
            row++;
        } else {
            col += dir;
        }
    }

    print_grid(grid, ROWS);
    return 0;
}
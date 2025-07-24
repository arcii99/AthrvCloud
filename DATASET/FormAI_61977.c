//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int MAX_ROWS = 10;
int MAX_COLS = 10;

int maze[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

int is_valid_location(int row, int col) { 
    if(row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && maze[row][col] == 0) {
        return 1;
    }
    return 0;
}

void print_maze() {
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int find_maze_route(int row, int col) {
    if(row == MAX_ROWS-1 && col == MAX_COLS-1) {
        maze[row][col] = 2;
        return 1;
    }
    if(is_valid_location(row, col)) {
        maze[row][col] = 2;
        if(find_maze_route(row+1, col)) {
            return 1;
        }
        if(find_maze_route(row, col+1)) {
            return 1;
        }
        if(find_maze_route(row-1, col)) {
            return 1;
        }
        if(find_maze_route(row, col-1)) {
            return 1;
        }
        maze[row][col] = 0;
        return 0;
    }
    return 0;
}

int main() {
    printf("Original Maze:\n");
    print_maze();
    
    printf("Finding Maze Route...\n");
    if(find_maze_route(1, 1)) {
        printf("Maze Route Found!\n");
        printf("Final Maze:\n");
        print_maze();
    } else {
        printf("Maze Route Not Found!\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

void print_maze() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void find_route(int row, int col) {
    maze[row][col] = '*';
    
    if(row == ROW-2 && col == COL-2) {
        printf("Route found!\n");
        print_maze();
        exit(0);
    }
    
    // move down
    if(maze[row+1][col] == '.') {
        find_route(row+1, col);
    }
    
    // move right
    if(maze[row][col+1] == '.') {
        find_route(row, col+1);
    }
    
    // move up
    if(maze[row-1][col] == '.') {
        find_route(row-1, col);
    }
    
    // move left
    if(maze[row][col-1] == '.') {
        find_route(row, col-1);
    }
    
    maze[row][col] = '.';    // backtracking
}

int main() {
    print_maze();
    printf("Finding route...\n");
    find_route(1, 1);
    printf("No route found!\n");
    
    return 0;
}
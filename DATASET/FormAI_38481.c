//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6 // height of the maze
#define COL 8 // width of the maze

// maze array: 1 represents wall, 0 represents path
int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1}
};

// printing the maze
void printMaze() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == 0) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

// checking if a given cell is valid or not
bool is_valid(int i, int j) {
    if(i<0 || i>=ROW || j<0 || j>=COL) {
        return false;
    }
    if(maze[i][j] == 1) {
        return false;
    }
    return true;
}

// recursive function to traverse the maze and find the path
bool find_path(int i, int j) {
    if(i == ROW-1 && j == COL-1) {
        maze[i][j] = 2;
        return true;
    }
    if(is_valid(i, j)) {
        maze[i][j] = 2;
        if(find_path(i+1, j)) {
            return true;
        }
        if(find_path(i, j+1)) {
            return true;
        }
        if(find_path(i-1, j)) {
            return true;
        }
        if(find_path(i, j-1)) {
            return true;
        }
        maze[i][j] = 0;
        return false;
    }
    return false;
}

int main() {
    printf("Original maze:\n");
    printMaze();
    
    if(find_path(0,0)) {
        printf("Path found:\n");
        printMaze();
    } else {
        printf("No path found.\n");
    }
    
    return 0;
}
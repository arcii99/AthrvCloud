//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

struct node {
    int row, col;
};

bool is_valid(int row, int col, int maze[][COL], bool visited[][COL]) {    
    return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && maze[row][col] && !visited[row][col]);    
}

void print_path(struct node path[], int path_length) {
    printf("Path: ");
    for(int i = 0; i < path_length; i++)
        printf("(%d,%d) ", path[i].row, path[i].col);
    printf("\n");
}

bool find_path(int maze[][COL], bool visited[][COL], int row, int col, struct node path[], int* path_index) {
    if((row == ROW-1) && (col == COL-1)) {
        path[(*path_index)++] = (struct node){row, col};
        print_path(path, *path_index);
        return true;
    }

    if(is_valid(row, col, maze, visited)) {
        visited[row][col] = true;
        path[(*path_index)++] = (struct node){row, col};

        // move down
        if(find_path(maze, visited, row+1, col, path, path_index))
            return true;
        
        // move right
        if(find_path(maze, visited, row, col+1, path, path_index))
            return true;
        
        // move up
        if(find_path(maze, visited, row-1, col, path, path_index))
            return true;
        
        // move left
        if(find_path(maze, visited, row, col-1, path, path_index))
            return true;

        // backtrack
        (*path_index)--;
    }

    return false;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    };

    bool visited[ROW][COL] = { { false } };
    struct node path[ROW*COL];
    int path_index = 0;

    if(find_path(maze, visited, 0, 0, path, &path_index) == false)
        printf("No path found\n");    
    
    return 0;
}
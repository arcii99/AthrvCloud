//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int row;
    int col;
};

int is_valid(char maze[][SIZE], int row, int col);
int find_route(char maze[][SIZE], struct Node start, struct Node end, int visited[][SIZE], struct Node* path, int count);
void print_path(struct Node* path, int count);
void distribute_rows(char maze[][SIZE], int count);

int main() {
    char maze[SIZE][SIZE] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '.', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '.', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '.', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'}
    };

    struct Node start = {1, 1};
    struct Node end = {8, 8};
    int visited[SIZE][SIZE] = {0};
    struct Node path[SIZE * SIZE];
    int count = find_route(maze, start, end, visited, path, 0);
    if (count == -1) {
        printf("No route found.\n");
    } else {
        print_path(path, count);
    }
    return 0;
}

int is_valid(char maze[][SIZE], int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && maze[row][col] != '#';
}

int find_route(char maze[][SIZE], struct Node start, struct Node end, int visited[][SIZE], struct Node* path, int count) {
    visited[start.row][start.col] = 1;
    if (start.row == end.row && start.col == end.col) {
        path[count] = start;
        return count + 1;
    }
    struct Node adjacent[] = {{start.row, start.col - 1}, // left
                              {start.row - 1, start.col}, // up
                              {start.row, start.col + 1}, // right
                              {start.row + 1, start.col}}; // down
    int i;
    for (i = 0; i < 4; i++) {
        int row = adjacent[i].row;
        int col = adjacent[i].col;
        if (is_valid(maze, row, col) && !visited[row][col]) {
            int new_count = find_route(maze, adjacent[i], end, visited, path, count + 1);
            if (new_count != -1) {
                path[count] = start;
                return new_count;
            }
        }
    }
    return -1;
}

void print_path(struct Node* path, int count) {
    printf("Path found: ");
    int i;
    for (i = count - 1; i >= 0; i--) {
        printf("(%d,%d)", path[i].row, path[i].col);
        if (i != 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void distribute_rows(char maze[][SIZE], int count) {
    // distribute rows to different nodes here
}
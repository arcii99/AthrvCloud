//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Define a structure to hold coordinates
typedef struct {
    int x;
    int y;
} Coords;

// Create a queue data structure
typedef struct {
    Coords arr[ROW * COL];
    int front;
    int rear;
} Queue;

// Define a function to check if a given cell is accessible or not
bool is_accessible(int grid[ROW][COL], bool visited[ROW][COL], int row_num, int col_num) {
    return (row_num >= 0 && row_num < ROW) &&
           (col_num >= 0 && col_num < COL) &&
           (grid[row_num][col_num] == 1 && !visited[row_num][col_num]);
}

// Define a function to print the path from start to end
void print_path(Coords parent[ROW][COL], Coords end) {
    if (parent[end.x][end.y].x == -1 && parent[end.x][end.y].y == -1) {
        return;
    }
    print_path(parent, parent[end.x][end.y]);
    printf("(%d, %d) ", end.x, end.y);
}

// Define a function to implement BFS pathfinding algorithm
void bfs(int grid[ROW][COL], Coords start, Coords end) {
    Queue q = {.front = -1, .rear = -1};
    bool visited[ROW][COL] = {false};
    Coords parent[ROW][COL] = {{-1, -1}};
    Coords movements[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    visited[start.x][start.y] = true;
    q.rear++;
    q.arr[q.rear] = start;

    while (q.front != q.rear) {
        q.front++;
        Coords current = q.arr[q.front];

        if (current.x == end.x && current.y == end.y) {
            printf("Path from start to end is: ");
            print_path(parent, end);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int row_num = current.x + movements[i].x;
            int col_num = current.y + movements[i].y;
            if (is_accessible(grid, visited, row_num, col_num)) {
                visited[row_num][col_num] = true;
                q.rear++;
                q.arr[q.rear] = (Coords){row_num, col_num};
                parent[row_num][col_num] = current;
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int grid[ROW][COL] = {{1, 0, 1, 1, 1},
                          {1, 0, 1, 0, 1},
                          {1, 1, 1, 0, 1},
                          {0, 0, 0, 0, 1},
                          {1, 1, 1, 0, 1}};
    Coords start = {0, 0};
    Coords end = {ROW - 1, COL - 1};
    bfs(grid, start, end);
    return 0;
}
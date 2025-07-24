//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 8

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
};

typedef struct {
    int row;
    int col;
} Position;

Position queue[ROWS * COLS];
int front = 0, rear = 0;

void enqueue(Position pos) {
    queue[rear++] = pos;
}

Position dequeue() {
    return queue[front++];
}

bool is_empty() {
    return front == rear;
}

void print_path(int path[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    if (maze[row][col] == 1) {
        return false;
    }
    return true;
}

void bfs(Position start, Position end) {
    int path[ROWS][COLS] = {0};
    bool visited[ROWS][COLS] = {false};

    enqueue(start);
    visited[start.row][start.col] = true;

    int row, col;
    while (!is_empty()) {
        Position curr = dequeue();
        row = curr.row;
        col = curr.col;

        if (row == end.row && col == end.col) {
            printf("Path found!\n");
            print_path(path);
            return;
        }

        if (is_valid(row + 1, col) && !visited[row + 1][col]) { // check down
            enqueue((Position) {row + 1, col});
            visited[row + 1][col] = true;
            path[row + 1][col] = path[row][col] + 1;
        }
        if (is_valid(row, col + 1) && !visited[row][col + 1]) { // check right
            enqueue((Position) {row, col + 1});
            visited[row][col + 1] = true;
            path[row][col + 1] = path[row][col] + 1;
        }
        if (is_valid(row - 1, col) && !visited[row - 1][col]) { // check up
            enqueue((Position) {row - 1, col});
            visited[row - 1][col] = true;
            path[row - 1][col] = path[row][col] + 1;
        }
        if (is_valid(row, col - 1) && !visited[row][col - 1]) { // check left
            enqueue((Position) {row, col - 1});
            visited[row][col - 1] = true;
            path[row][col - 1] = path[row][col] + 1;
        }
    }
    printf("No path found.");
}

int main() {
    Position start = {1, 1};
    Position end = {4, 6};
    bfs(start, end);
    return 0;
}
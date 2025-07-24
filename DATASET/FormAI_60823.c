//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 7
#define COLS 10

typedef struct {
    int row, col;
} coord;

coord start = {1, 0};
coord end = {ROWS - 2, COLS - 1};

bool maze[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the queue
typedef struct {
    coord points[ROWS * COLS];
    int front, rear;
} Queue;

Queue q;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Add item to the queue
void enqueue(Queue *q, coord point) {
    q->points[q->rear++] = point;
}

// Remove item from the queue
coord dequeue(Queue *q) {
    return q->points[q->front++];
}

// Check if given cell is valid for adding to queue
bool isValid(int row, int col, bool visited[][COLS]) {
    if (row >= 0 && col >= 0 && row < ROWS && col < COLS && maze[row][col] != 1 && !visited[row][col]) {
        return true;
    }
    return false;
}

// Print the maze
void printMaze(bool visited[][10]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == start.row && j == start.col) {
                printf("S ");
            } else if (i == end.row && j == end.col) {
                printf("E ");
            } else if (visited[i][j]) {
                printf(". ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Find the shortest path using BFS
void bfs() {
    bool visited[ROWS][COLS];
    memset(visited, false, sizeof visited); // mark all cells as unvisited

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    coord parent[ROWS][COLS];
    memset(parent, -1, sizeof parent);

    initQueue(&q);
    visited[start.row][start.col] = true;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        coord current = dequeue(&q);

        if (current.row == end.row && current.col == end.col) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int row = current.row + dRow[i];
            int col = current.col + dCol[i];

            if (isValid(row, col, visited)) {
                visited[row][col] = true;
                coord point = {row, col};
                enqueue(&q, point);
                parent[row][col] = current;
            }
        }
    }

    if (parent[end.row][end.col].row == -1 && parent[end.row][end.col].col == -1) {
        printf("No path found!\n");
    } else {
        printf("Path found:\n");
        coord current = end;
        bool path[ROWS][COLS];
        memset(path, false, sizeof path);
        while (!(current.row == start.row && current.col == start.col)) {
            path[current.row][current.col] = true;
            current = parent[current.row][current.col];
        }
        path[start.row][start.col] = true;
        printMaze(path);
    }
}

int main() {
    printf("Starting maze:\n");
    printMaze(maze);
    bfs();
    return 0;
}
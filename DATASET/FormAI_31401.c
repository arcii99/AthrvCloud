//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>

// Defining the size of the map
#define ROW 10
#define COL 15

// Defining the possible directions a robot can move in
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Creating a data structure for the map
int map[ROW][COL] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Defining the points in the map
typedef struct point {
    int row;
    int col;
} Point;

// Defining the queue to keep track of points to visit
typedef struct queue {
    Point arr[ROW*COL];
    int front;
    int rear;
} Queue;

// Initializing the queue
Queue q = {{
    { 0, 0 }
}, 0, 0};

// Function to check if a point is valid
int isValid(int row, int col) {
    if (row < 0 || row >= ROW) {
        return 0;
    }
    if (col < 0 || col >= COL) {
        return 0;
    }
    if (map[row][col] == 1) {
        return 0;
    }
    return 1;
}

// Function to add a point to the queue
void enqueue(int row, int col) {
    q.rear++;
    q.arr[q.rear].row = row;
    q.arr[q.rear].col = col;
}

// Function to remove a point from the queue
void dequeue() {
    q.front++;
}

// Function to check if the queue is empty
int isQueueEmpty() {
    if (q.front > q.rear) {
        return 1;
    }
    return 0;
}

// Function to return the first point in the queue
Point front() {
    return q.arr[q.front];
}

// Function to find the shortest path
void bfs(Point start, Point end) {
    int visited[ROW][COL] = { 0 };
    int distance[ROW][COL];
    int direction[ROW][COL];
    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            distance[i][j] = -1;
            direction[i][j] = -1;
        }
    }

    visited[start.row][start.col] = 1;
    distance[start.row][start.col] = 0;
    enqueue(start.row, start.col);

    while (!isQueueEmpty()) {
        Point current = front();
        dequeue();

        if (current.row == end.row && current.col == end.col) {
            break;
        }

        if (isValid(current.row - 1, current.col) && !visited[current.row - 1][current.col]) {
            visited[current.row - 1][current.col] = 1;
            distance[current.row - 1][current.col] = distance[current.row][current.col] + 1;
            direction[current.row - 1][current.col] = NORTH;
            enqueue(current.row - 1, current.col);
        }

        if (isValid(current.row, current.col + 1) && !visited[current.row][current.col + 1]) {
            visited[current.row][current.col + 1] = 1;
            distance[current.row][current.col + 1] = distance[current.row][current.col] + 1;
            direction[current.row][current.col + 1] = EAST;
            enqueue(current.row, current.col + 1);
        }

        if (isValid(current.row + 1, current.col) && !visited[current.row + 1][current.col]) {
            visited[current.row + 1][current.col] = 1;
            distance[current.row + 1][current.col] = distance[current.row][current.col] + 1;
            direction[current.row + 1][current.col] = SOUTH;
            enqueue(current.row + 1, current.col);
        }

        if (isValid(current.row, current.col - 1) && !visited[current.row][current.col - 1]) {
            visited[current.row][current.col - 1] = 1;
            distance[current.row][current.col - 1] = distance[current.row][current.col] + 1;
            direction[current.row][current.col - 1] = WEST;
            enqueue(current.row, current.col - 1);
        }
    }

    if (distance[end.row][end.col] == -1) {
        printf("No path found.");
    }
    else {
        printf("Shortest path: %d\n", distance[end.row][end.col]);
        printf("Path taken (in reverse):\n");
        Point current = end;
        while (current.row != start.row || current.col != start.col) {
            switch (direction[current.row][current.col]) {
                case NORTH:
                    printf("(%d,%d) -> ", current.row, current.col);
                    current.row++;
                    break;
                case EAST:
                    printf("(%d,%d) -> ", current.row, current.col);
                    current.col--;
                    break;
                case SOUTH:
                    printf("(%d,%d) -> ", current.row, current.col);
                    current.row--;
                    break;
                case WEST:
                    printf("(%d,%d) -> ", current.row, current.col);
                    current.col++;
                    break;
                default:
                    break;
            }
        }
        printf("(%d,%d)", start.row, start.col);
    }
}

int main() {
    Point start = { 0, 0 };
    Point end = { 9, 14 };
    bfs(start, end);

    return 0;
}
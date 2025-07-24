//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

int maze[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0}
};

// Structure to hold coordinates
typedef struct {
    int row;
    int col;
} Coord;

// Queue functions
typedef struct {
    Coord items[ROW * COL];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    if (q->rear == -1) {
        return true;
    }
    return false;
}

bool isQueueFull(Queue* q) {
    if (q->rear == ROW * COL - 1) {
        return true;
    }
    return false;
}

void enqueue(Queue* q, Coord val) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
    }
}

Coord dequeue(Queue* q) {
    Coord item;
    item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

int main() {
    Queue q;
    initQueue(&q);

    Coord start = {START_ROW, START_COL};
    Coord end = {END_ROW, END_COL};

    enqueue(&q, start);

    bool visited[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }
    visited[start.row][start.col] = true;

    int foundPath = 0;

    while (!isQueueEmpty(&q)) {
        Coord current = dequeue(&q);

        if (current.row == end.row && current.col == end.col) {
            foundPath = 1;
            break;
        }

        // check if top is valid
        if (current.row - 1 >= 0 && maze[current.row - 1][current.col] == 0 && !visited[current.row - 1][current.col]) {
            Coord newCoord = {current.row - 1, current.col};
            enqueue(&q, newCoord);
            visited[current.row - 1][current.col] = true;
        }

        // check if bottom is valid
        if (current.row + 1 < ROW && maze[current.row + 1][current.col] == 0 && !visited[current.row + 1][current.col]) {
            Coord newCoord = {current.row + 1, current.col};
            enqueue(&q, newCoord);
            visited[current.row + 1][current.col] = true;
        }

        // check if left is valid
        if (current.col - 1 >= 0 && maze[current.row][current.col - 1] == 0 && !visited[current.row][current.col - 1]) {
            Coord newCoord = {current.row, current.col - 1};
            enqueue(&q, newCoord);
            visited[current.row][current.col - 1] = true;
        }

        // check if right is valid
        if (current.col + 1 < COL && maze[current.row][current.col + 1] == 0 && !visited[current.row][current.col + 1]) {
            Coord newCoord = {current.row, current.col + 1};
            enqueue(&q, newCoord);
            visited[current.row][current.col + 1] = true;
        }
    }

    if (foundPath) {
        printf("Path found:\n");
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                if (maze[i][j] == 1) {
                    printf("X ");
                } else {
                    if (visited[i][j]) {
                        printf(". ");
                    } else {
                        printf("  ");
                    }
                }
            }
            printf("\n");
        }
    } else {
        printf("Path not found\n");
    }

    return 0;
}
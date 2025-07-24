//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int grid[ROW][COL];
bool visited[ROW][COL];

typedef struct node {
    int row;
    int col;
} Node;

typedef struct queue {
    Node *nodes[ROW * COL];
    int front, rear;
} Queue;

Node* createNode(int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, Node* node) {
    queue->rear++;
    queue->nodes[queue->rear] = node;
    if (queue->front == -1) {
        queue->front++;
    }
}

Node* dequeue(Queue* queue) {
    Node* dequeuedNode = queue->nodes[queue->front];
    queue->front++;
    return dequeuedNode;
}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && !visited[row][col]);
}

void bfs(int startRow, int startCol, int endRow, int endCol) {
    Queue* queue = createQueue();
    visited[startRow][startCol] = true;
    enqueue(queue, createNode(startRow, startCol));

    int rowMoves[] = {-1, 0, 1, 0};
    int colMoves[] = {0, 1, 0, -1};

    while (queue->front <= queue->rear) {
        Node* currentNode = dequeue(queue);

        if (currentNode->row == endRow && currentNode->col == endCol) {
            printf("Path found!\n");
            exit(0);
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = currentNode->row + rowMoves[i];
            int nextCol = currentNode->col + colMoves[i];
            
            if (isValidMove(nextRow, nextCol) && grid[nextRow][nextCol] == 0) {
                visited[nextRow][nextCol] = true;
                enqueue(queue, createNode(nextRow, nextCol));
            }
        }
    }
    printf("Path not found.\n");
}

int main() {
    // Initialize the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Choose start and end points
    int startX = rand() % ROW;
    int startY = rand() % COL;
    int endX = rand() % ROW;
    int endY = rand() % COL;

    printf("Grid:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\nStart: (%d,%d)\n", startX, startY);
    printf("End: (%d,%d)\n\n", endX, endY);

    bfs(startX, startY, endX, endY);

    return 0;
}
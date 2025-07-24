//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG //uncomment to enable debug messages

#define ROW 6
#define COL 6

char maze[ROW][COL] = {
    {'S', '#', '.', '#', '.', '#'},
    {'.', '#', '.', '#', '.', '#'},
    {'.', '#', '.', '#', '.', '.'},
    {'.', '.', '.', '.', '.', '#'},
    {'.', '#', '.', '#', '.', '#'},
    {'.', '.', '.', '#', '.', 'E'}
};

int startRow = 0, startCol = 0;
int endRow = ROW-1, endCol = COL-1;

typedef struct Node {
    int row, col;
    struct Node* next;
} Node;

Node* createNode(int row, int col) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    return node;
}

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int row, int col) {
    Node* node = createNode(row, col);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

int findPath() {
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    int distance[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            distance[i][j] = -1;
        }
    }

    visited[startRow][startCol] = true;
    distance[startRow][startCol] = 0;

    Queue* queue = createQueue();
    enqueue(queue, startRow, startCol);

    while (!isEmpty(queue)) {
        int currRow = queue->front->row;
        int currCol = queue->front->col;
        dequeue(queue);

        if (currRow == endRow && currCol == endCol) {
            break;
        }

        //up
        if (currRow > 0 && maze[currRow-1][currCol] != '#' && !visited[currRow-1][currCol]) {
            visited[currRow-1][currCol] = true;
            distance[currRow-1][currCol] = distance[currRow][currCol] + 1; //update distance
            enqueue(queue, currRow-1, currCol);
        }

        //down
        if (currRow < ROW-1 && maze[currRow+1][currCol] != '#' && !visited[currRow+1][currCol]) {
            visited[currRow+1][currCol] = true;
            distance[currRow+1][currCol] = distance[currRow][currCol] + 1; //update distance
            enqueue(queue, currRow+1, currCol);
        }

        //left
        if (currCol > 0 && maze[currRow][currCol-1] != '#' && !visited[currRow][currCol-1]) {
            visited[currRow][currCol-1] = true;
            distance[currRow][currCol-1] = distance[currRow][currCol] + 1; //update distance
            enqueue(queue, currRow, currCol-1);
        }

        //right
        if (currCol < COL-1 && maze[currRow][currCol+1] != '#' && !visited[currRow][currCol+1]) {
            visited[currRow][currCol+1] = true;
            distance[currRow][currCol+1] = distance[currRow][currCol] + 1; //update distance
            enqueue(queue, currRow, currCol+1);
        }
    }

#ifdef DEBUG
    //debug print distance matrix
    printf("Distance Matrix:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }
#endif

    return distance[endRow][endCol];
}

int main() {
    printf("Maze Route Finder\n\n");

    //print maze
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c\t", maze[i][j]);
        }
        printf("\n");
    }

    //find shortest path
    int steps = findPath();

    //print results
    printf("\nNumber of steps required to reach destination: %d\n", steps);
    return 0;
}
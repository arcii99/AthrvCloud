//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ','#','#'},
    {'#','#','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ',' ',' ','#',' ','#','#',' ','#'},
    {'#',' ','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#',' ','#',' ','#','#'},
    {'#','#','#',' ','#',' ','#',' ','#','#'},
    {'#',' ',' ',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ',' ',' ','#','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}};

char visited[ROW][COL];

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Node {
    Position position;
    struct Node *nextNode;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(Queue *queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

void enqueue(Queue *queue, Position position) {
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->position = position;
    node->nextNode = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->nextNode = node;
        queue->rear = node;
    }
}

Position dequeue(Queue *queue) {
    Node *current;
    Position position;
    
    if (isQueueEmpty(queue)) {
        position.x = -1;
        position.y = -1;
        return position;
    }
    
    current = queue->front;
    position = current->position;
    
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->nextNode;
    }
    
    free(current);
    
    return position;
}

void printMaze() {
    int i, j;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        
        printf("\n");
    }
}

void printVisited() {
    int i, j;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", visited[i][j]);
        }
        
        printf("\n");
    }
}

void resetVisited() {
    int i, j;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = ' ';
        }
    }
}

int bfs(Position start, Position end) {
    int i, j, x, y;
    Queue queue;
    
    visited[start.x][start.y] = 'X';
    initializeQueue(&queue);
    enqueue(&queue, start);
    
    while (!isQueueEmpty(&queue)) {
        Position currentPosition = dequeue(&queue);
        
        if (currentPosition.x == end.x && currentPosition.y == end.y) {
            visited[currentPosition.x][currentPosition.y] = 'X';
            return 1;
        }
        
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                x = currentPosition.x + i;
                y = currentPosition.y + j;
                
                if (x >=0 && x < ROW && y >=0 && y < COL && visited[x][y] == ' ' && (maze[x][y] == ' ' || maze[x][y] == 'E')) {
                    visited[x][y] = 'X';
                    enqueue(&queue, (Position){x, y});
                }
            }
        }
    }
    
    return 0;
}

int main() {
    Position start = {1, 1};
    Position end = {8, 8};
    
    printf("Maze:\n");
    printMaze();
    printf("\n");
    
    if (bfs(start, end)) {
        printf("Shortest path:\n");
        printVisited();
        printf("\n");
    } else {
        printf("No path found\n");
    }
    
    resetVisited();
    
    start.x = 7;
    start.y = 1;
    
    printf("Maze:\n");
    printMaze();
    printf("\n");
    
    if (bfs(start, end)) {
        printf("Shortest path:\n");
        printVisited();
        printf("\n");
    } else {
        printf("No path found\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define ROW 10
#define COL 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    int up, down, left, right;
} Direction;

// Maze and visited arrays
char maze[ROW][COL + 1];
bool visited[ROW][COL];

// Starting and ending points
Point start = {.x = 0, .y = 0};
Point end = {.x = ROW - 1, .y = COL - 1};

// Directions array
Direction directions[4] = {
    {.up = -1, .down = 0, .left = 0, .right = 0},
    {.up = 0, .down = -1, .left = 0, .right = 0},
    {.up = 0, .down = 0, .left = -1, .right = 0},
    {.up = 0, .down = 0, .left = 0, .right = -1}
};

// Queue structure for BFS
typedef struct Node {
    Point point;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    pthread_mutex_t lock;
} Queue;

// Initializes the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    pthread_mutex_init(&q->lock, NULL);
}

// Adds an element to the queue
void enqueue(Queue* q, Point p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point = p;
    newNode->next = NULL;

    pthread_mutex_lock(&q->lock);

    if(q->front == NULL && q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    pthread_mutex_unlock(&q->lock);
}

// Removes an element from the queue
Point dequeue(Queue* q) {
    pthread_mutex_lock(&q->lock);

    Node* temp = q->front;
    Point p = temp->point;
    q->front = q->front->next;
    free(temp);

    // If front becomes NULL, rear also becomes NULL
    if(q->front == NULL) {
        q->rear = NULL;
    }

    pthread_mutex_unlock(&q->lock);

    return p;
}

// Checks if the point is within the maze boundaries
bool isWithinBoundaries(int x, int y) {
    return x >= 0 && y >= 0 && x < ROW && y < COL;
}

// Checks if the point is a valid path
bool isValidPath(int x, int y) {
    return maze[x][y] == ' ' && !visited[x][y];
}

// Checks if the point is the end point
bool isEndPoint(int x, int y) {
    return x == end.x && y == end.y;
}

// BFS algorithm to find the shortest path
void bfs(Queue* q, Point current, Point parent, bool* foundEnd) {
    visited[current.x][current.y] = true;

    if(isEndPoint(current.x, current.y)) {
        *foundEnd = true;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int x = current.x + directions[i].up + directions[i].down;
        int y = current.y + directions[i].left + directions[i].right;

        if(isWithinBoundaries(x, y) && isValidPath(x, y)) {
            Point next = {.x = x, .y = y};
            enqueue(q, next);
            visited[x][y] = true;
        }
    }

    while(q->front != NULL && !*foundEnd) {
        Point next = dequeue(q);
        bfs(q, next, current, foundEnd);
    }
}

// Prints the maze
void printMaze() {
    for(int i = 0; i < ROW; i++) {
        printf("%s\n", maze[i]);
    }
}

// Randomly generates the maze
void generateMaze() {
    srand(time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(i == start.x && j == start.y) {
                maze[i][j] = 'S';
            }
            else if(i == end.x && j == end.y) {
                maze[i][j] = 'E';
            }
            else if(rand() % 4 == 0) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = ' ';
            }
            visited[i][j] = false;
        }
        maze[i][COL] = '\0';
    }
}

int main() {
    // Initialize the queue
    Queue q;
    initQueue(&q);

    // Generate the maze
    generateMaze();

    // Print the generated maze
    printf("Generated Maze:\n");
    printMaze();

    // Find the shortest path
    bool foundEnd = false;
    bfs(&q, start, start, &foundEnd);

    // Reset the visited array
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    // Mark the shortest path
    if(foundEnd) {
        Point current = end;
        Point parent = current;
        while(current.x != start.x || current.y != start.y) {
            visited[current.x][current.y] = true;
            for(int i = 0; i < 4; i++) {
                int x = current.x + directions[i].up + directions[i].down;
                int y = current.y + directions[i].left + directions[i].right;

                if(x == parent.x && y == parent.y) {
                    parent.x = current.x;
                    parent.y = current.y;
                    current.x = x;
                    current.y = y;
                    break;
                }
            }
        }
        visited[start.x][start.y] = true;

        // Print the maze with the shortest path
        printf("\nMaze with the shortest path:\n");
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(visited[i][j]) {
                    printf(".");
                }
                else {
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }
    }
    else {
        printf("\nNo path found.\n");
    }

    return 0;
}
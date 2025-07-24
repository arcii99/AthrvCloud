//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 20
#define MAX_COL 20

// Maze to be traversed
char maze[MAX_ROW][MAX_COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Position of start point and end point
struct position {
    int x, y;
} start, end;

// Queue
struct queue {
    struct position data[MAX_ROW * MAX_COL];
    int front, rear;
} q;

// Function to initialize queue
void initQueue(struct queue *q) {
    q->front = q->rear = 0;
}

// Function to check queue is empty or not
int isEmpty(struct queue *q) {
    return (q->front == q->rear) ? 1 : 0;
}

// Function to push data into queue
void enqueue(struct queue *q, struct position pos) {
    q->data[q->rear++] = pos;
}

// Function to get data from queue
struct position dequeue(struct queue *q) {
    return q->data[q->front++];
}

// Function to check whether a position is valid or not
int isValid(int row, int col) {
    return (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL) ? 1 : 0;
}

// Function to print the maze 
void printMaze() {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find the path from start to end
int findPath() {
    int i, j;
    struct position pos, next;

    // Initializing queue and visited array
    initQueue(&q);
    int visited[MAX_ROW][MAX_COL] = {0};

    // Pushing start position into queue
    pos.x = start.x;
    pos.y = start.y;
    enqueue(&q, pos);

    // Loop until queue becomes empty
    while (!isEmpty(&q)) {
        // Get data from queue
        pos = dequeue(&q);

        // If we reach to end point then return true
        if (pos.x == end.x && pos.y == end.y) {
            return 1;
        }

        // Checking all 4 directions (up, down, left, right)
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};
        for (i = 0; i < 4; i++) {
            next.x = pos.x + x[i];
            next.y = pos.y + y[i];

            // If next position is valid and not visited and there is no wall then push into queue
            if (isValid(next.x, next.y) && !visited[next.x][next.y] && maze[next.x][next.y] == ' ') {
                visited[next.x][next.y] = 1;
                enqueue(&q, next);
            }
        }
    }

    // If we could not find the path then return false
    return 0;
}

int main() {
    // Setting start position and end position
    start.x = 1;
    start.y = 1;
    end.x = 15;
    end.y = 18;

    // Printing the maze
    printf("Maze:\n\n");
    printMaze();

    // Initializing visited array and finding the path
    int visited[MAX_ROW][MAX_COL] = {0};
    if (findPath()) {
        // Printing the maze with path
        int i;
        for (i = 0; i < q.rear; i++) {
            printf("[%d, %d] -> ", q.data[i].x, q.data[i].y);
            visited[q.data[i].x][q.data[i].y] = 1;
        }
        printf("\n\nMaze with path:\n\n");

        for (i = 0; i < MAX_ROW; i++) {
            int j;
            for (j = 0; j < MAX_COL; j++) {
                if (visited[i][j]) {
                    printf(". ");
                } else {
                    printf("%c ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("\nPath not found!\n");
    }

    return 0;
}
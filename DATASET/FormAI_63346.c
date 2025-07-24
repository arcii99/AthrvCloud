//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 20

int maze[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point point;
    int previous;
} Queue;

int front = -1;
int rear = -1;
Queue queue[ROW*COL];
int visited[ROW*COL] = {0};

void enqueue(Point start) {
    if (front == -1) {
        front++;
        rear++;
        queue[rear].point = start;
        queue[rear].previous = -1;
        visited[0] = 1;
        return;
    }
    rear++;
    queue[rear].point = start;
    queue[rear].previous = front;
    front++;
}

Point dequeue() {
    Point point = queue[front].point;
    front++;
    return point;
}

int isQueueEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void generateMaze() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (rand()%5 == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
}

void printMaze() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("# "); //wall
            } else {
                printf(". "); //path
            }
        }
        printf("\n");
    }
}

int getDirection(Point current, Point *neighbors) {
    int row = current.row;
    int col = current.col;
    int i = 0;
    if (maze[row+1][col] == 0 && visited[(row+1)*COL+col] == 0) {
        neighbors[i].row = row+1;
        neighbors[i].col = col;
        i++;
    }
    if (maze[row-1][col] == 0 && visited[(row-1)*COL+col] == 0) {
        neighbors[i].row = row-1;
        neighbors[i].col = col;
        i++;
    }
    if (maze[row][col+1] == 0 && visited[row*COL+col+1] == 0) {
        neighbors[i].row = row;
        neighbors[i].col = col+1;
        i++;
    }
    if (maze[row][col-1] == 0 && visited[row*COL+col-1] == 0) {
        neighbors[i].row = row;
        neighbors[i].col = col-1;
        i++;
    }
    return i;
}

void printPath(Point *path, int index) {
    int i;
    for (i = index; i >= 0; i--) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
}

void findPath(Point start, Point end) {
    int i, index = -1;
    Point current;
    Point neighbors[4];
    enqueue(start);
    int direction, previous;
    while (!isQueueEmpty()) {
        current = dequeue();
        visited[current.row*COL+current.col] = 1;
        if (current.row == end.row && current.col == end.col) {
            Point path[ROW*COL];
            path[++index] = current;
            previous = queue[front].previous;
            while (previous != -1) {
                path[++index] = queue[previous].point;
                previous = queue[previous].previous;
            }
            printf("Path: ");
            printPath(path, index);
            return;
        }
        direction = getDirection(current, neighbors);
        for (i = 0; i < direction; i++) {
            enqueue(neighbors[i]);
        }
    }
    printf("Target unreachable");
}

int main() {
    generateMaze();
    printf("Maze: \n");
    printMaze();
    printf("\n");
    Point start = {1, 1};
    Point end = {ROW-2, COL-2};
    printf("Start: (%d, %d)\n", start.row, start.col);
    printf("End: (%d, %d)\n", end.row, end.col);
    findPath(start, end);
    return 0;
}
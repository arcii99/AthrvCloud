//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

int startRow, startCol, endRow, endCol;

typedef struct {
    int row;
    int col;
} Point;

Point queue[MAX_ROWS * MAX_COLS];
int front, rear;

void enqueue(int row, int col) {
    queue[rear].row = row;
    queue[rear].col = col;
    rear++;
}

Point dequeue() {
    Point item;
    item.row = queue[front].row;
    item.col = queue[front].col;
    front++;
    return item;
}

int isEmpty() {
    return front == rear;
}

void printMaze() {
    printf("\n");
    for(int row = 0; row < MAX_ROWS; row++) {
        for(int col = 0; col < MAX_COLS; col++) {
            printf("%d ", maze[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void printPath() {
    printf("\n");
    for(int row = 0; row < MAX_ROWS; row++) {
        for(int col = 0; col < MAX_COLS; col++) {
            if(maze[row][col] == -1) {
                printf("X ");
            } else if(maze[row][col] == 0) {
                printf("_ ");
            } else {
                printf("%d ", maze[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isValid(int row, int col) {
    return (row >= 0 && col >= 0 && row < MAX_ROWS && col < MAX_COLS && maze[row][col] == 0);
}

void markNeighbors(Point current) {
    int row = current.row;
    int col = current.col;
    int step = maze[row][col];
    if(isValid(row-1, col)) {
        maze[row-1][col] = step+1;
        enqueue(row-1, col);
    }
    if(isValid(row+1, col)) {
        maze[row+1][col] = step+1;
        enqueue(row+1, col);
    }
    if(isValid(row, col-1)) {
        maze[row][col-1] = step+1;
        enqueue(row, col-1);
    }
    if(isValid(row, col+1)) {
        maze[row][col+1] = step+1;
        enqueue(row, col+1);
    }
}

void findPath() {
    front = rear = 0;
    enqueue(startRow, startCol);
    maze[startRow][startCol] = 1;
    while(!isEmpty()) {
        Point current = dequeue();
        if(current.row == endRow && current.col == endCol) {
            return;
        }
        markNeighbors(current);
    }
}

int main() {
    printf("\n Maze:\n");
    printMaze();
    printf("\n Enter starting row and column: ");
    scanf("%d %d", &startRow, &startCol);
    printf("\n Enter ending row and column: ");
    scanf("%d %d", &endRow, &endCol);

    findPath();

    printf("\n Path:\n");
    printPath();
    printf("\n");

    return 0;
}
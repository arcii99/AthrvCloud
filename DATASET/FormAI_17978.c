//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

#define ROW 6
#define COLUMN 6

int maze[ROW][COLUMN] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0}
};

struct Node {
    int row, column;
};

struct Queue {
    struct Node items[ROW*COLUMN];
    int front, rear;
};

struct Queue q;

void initQueue() {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty() {
    if(q.rear == -1)
        return true;
    return false;
}

void enqueue(int row, int column) {
    if(q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    q.items[q.rear].row = row;
    q.items[q.rear].column = column;
}

struct Node dequeue() {
    struct Node item = q.items[q.front];
    q.front++;
    if(q.front > q.rear) {
        q.front = -1;
        q.rear = -1;
    }
    return item;
}

bool isValid(int row, int column) {
    if(row < 0 || row >= ROW || column < 0 || column >= COLUMN || maze[row][column] > 0) {
        return false;
    }
    return true;
}

void printPath(int path[ROW][COLUMN], int startX, int startY, int endX, int endY) {
    printf("The path from (%d,%d) to (%d,%d):\n", startX, startY, endX, endY);
    int row = endX, column = endY;
    while(row != startX || column != startY) {
        printf("(%d,%d)\n", row, column);
        int tempRow = path[row][column] / 10;
        int tempColumn = path[row][column] % 10;
        row = tempRow;
        column = tempColumn;
    }
    printf("(%d,%d)\n", row, column);
}

void findPath(int startX, int startY, int endX, int endY) {
    int path[ROW][COLUMN];
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COLUMN;j++) {
            path[i][j] = -1;
        }
    }
    initQueue();
    maze[startX][startY] = -1;
    enqueue(startX, startY);
    while(!isEmpty()) {
        struct Node current = dequeue();
        int row = current.row;
        int column = current.column;
        if(row == endX && column == endY) {
            printPath(path, startX, startY, endX, endY);
            return;
        }
        
        if(isValid(row-1, column)) {
            maze[row-1][column] = -1;
            path[row-1][column] = (row*10)+column;
            enqueue(row-1, column);
        }
        
        if(isValid(row+1, column)) {
            maze[row+1][column] = -1;
            path[row+1][column] = (row*10)+column;
            enqueue(row+1, column);
        }
        
        if(isValid(row, column-1)) {
            maze[row][column-1] = -1;
            path[row][column-1] = (row*10)+column;
            enqueue(row, column-1);
        }
        
        if(isValid(row, column+1)) {
            maze[row][column+1] = -1;
            path[row][column+1] = (row*10)+column;
            enqueue(row, column+1);
        }
    }
    printf("The path from (%d,%d) to (%d,%d) does not exist.\n", startX, startY, endX, endY);
}

int main() {
    int startX = 0, startY = 0, endX = 5, endY = 5;
    findPath(startX, startY, endX, endY);
    return 0;
}
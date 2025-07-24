//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define START_ROW 0
#define START_COL 0

typedef struct {
    int row;
    int col;
} Point;

int maze[ROWS][COLS] = {
    {1,1,1,0,1,1,0,0,0,1},
    {0,0,1,1,1,0,1,1,1,1},
    {0,1,1,0,1,0,1,0,0,0},
    {0,1,0,1,1,1,1,1,1,0},
    {1,1,0,1,0,0,0,0,1,0},
    {1,0,0,0,0,1,1,1,1,0},
    {1,1,1,1,1,0,0,0,1,0},
    {1,0,0,0,1,0,1,0,0,0},
    {1,0,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,0,0,1}
};

Point stack[ROWS * COLS];
int top = -1;

void push(Point p) {
    if (top < ROWS * COLS - 1) {
        stack[++top] = p;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

Point peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == ROWS * COLS - 1;
}

void printStack() {
    printf("Path: ");
    for (int i = 0; i <= top; i++) {
        printf("(%d,%d) ", stack[i].row, stack[i].col);
    }
    printf("\n");
}

void printMaze() {
    printf("Maze: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(int row, int col) {
    Point p = {row, col};
    push(p);
    maze[row][col] = 2;  // mark as visited
    if (row == ROWS - 1 && col == COLS - 1) {  // reached end
        return 1;
    }
    if (row > 0 && maze[row-1][col] == 1 && findPath(row-1, col)) {  // up
        return 1;
    }
    if (row < ROWS - 1 && maze[row+1][col] == 1 && findPath(row+1, col)) {  // down
        return 1;
    }
    if (col > 0 && maze[row][col-1] == 1 && findPath(row, col-1)) {  // left
        return 1;
    }
    if (col < COLS - 1 && maze[row][col+1] == 1 && findPath(row, col+1)) {  // right
        return 1;
    }
    pop();
    return 0;
}

int main() {
    printf("Finding route in a maze...\n");
    printMaze();
    printf("\n");
    if (findPath(START_ROW, START_COL)) {
        printStack();
    } else {
        printf("No path found!\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

int maze[ROWS][COLS];
int stack[ROWS*COLS][2];
int top = -1;

struct Position {
    int row;
    int col;
} start = {0, 0}, end = {ROWS-1, COLS-1};

void initializeMaze() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = rand()%2;
        }
    }
    maze[start.row][start.col] = 0;
    maze[end.row][end.col] = 0;
}

void printMaze() {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", maze[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

int isValidMove(int row, int col) {
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return 0;
    }
    if(maze[row][col] == 1) {
        return 0;
    }
    return 1;
}

void push(int row, int col) {
    top++;
    stack[top][0] = row;
    stack[top][1] = col;
}

void pop() {
    top--;
}

int isEmpty() {
    return top == -1;
}

void findRoute() {
    push(start.row, start.col);
    int currRow = start.row, currCol = start.col;
    while(!isEmpty()) {
        currRow = stack[top][0];
        currCol = stack[top][1];
        if(currRow == end.row && currCol == end.col) {
            return;
        }
        if(isValidMove(currRow+1, currCol)) {
            maze[currRow+1][currCol] = maze[currRow][currCol] + 1;
            push(currRow+1, currCol);
        } else if(isValidMove(currRow, currCol+1)) {
            maze[currRow][currCol+1] = maze[currRow][currCol] + 1;
            push(currRow, currCol+1);
        } else if(isValidMove(currRow-1, currCol)) {
            maze[currRow-1][currCol] = maze[currRow][currCol] + 1;
            push(currRow-1, currCol);
        } else if(isValidMove(currRow, currCol-1)) {
            maze[currRow][currCol-1] = maze[currRow][currCol] + 1;
            push(currRow, currCol-1);
        } else {
            pop();
        }
    }
}

void printRoute() {
    printf("\n");
    int row = end.row, col = end.col, currValue = maze[row][col]-1;
    while(row != start.row || col != start.col) {
        if(isValidMove(row+1, col) && (maze[row+1][col] == currValue)) {
            row++;
        } else if(isValidMove(row, col+1) && (maze[row][col+1] == currValue)) {
            col++;
        } else if(isValidMove(row-1, col) && (maze[row-1][col] == currValue)) {
            row--;
        } else if(isValidMove(row, col-1) && (maze[row][col-1] == currValue)) {
            col--;
        }
        currValue--;
        maze[row][col] = 2;
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", maze[i][j] == 1 ? '#' : (maze[i][j] == 2 ? '*' : ' '));
        }
        printf("\n");
    }
}

int main() {
    initializeMaze();
    printMaze();
    findRoute();
    printRoute();
    return 0;
}
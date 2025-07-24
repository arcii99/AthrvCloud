//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

int maze[ROWS][COLS];
int visited[ROWS][COLS];
int stackX[ROWS*COLS], stackY[ROWS*COLS];
int top = -1;
int startX, startY, endX, endY;

void generateMaze() {
    // Generate random maze
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }

    // Set start and end points
    startX = rand() % ROWS;
    startY = 0;
    endX = rand() % ROWS;
    endY = COLS-1;
    maze[startX][startY] = 0;
    maze[endX][endY] = 0;
}

void push(int x, int y) {
    top++;
    stackX[top] = x;
    stackY[top] = y;
}

void pop() {
    top--;
}

int isStackEmpty() {
    return top == -1;
}

void printMaze() {
    // Print generated maze
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1)
                printf("# ");
            else if(i == startX && j == startY)
                printf("S ");
            else if(i == endX && j == endY)
                printf("E ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solveMaze() {
    visited[startX][startY] = 1;
    push(startX, startY);

    while(!isStackEmpty()) {
        int x = stackX[top];
        int y = stackY[top];

        if(x == endX && y == endY) {
            // Reached the end
            return;
        }

        int foundPath = 0;
        if(x-1 >= 0 && maze[x-1][y] == 0 && !visited[x-1][y]) {
            // Check up
            visited[x-1][y] = 1;
            push(x-1, y);
            foundPath = 1;
        }
        else if(x+1 < ROWS && maze[x+1][y] == 0 && !visited[x+1][y]) {
            // Check down
            visited[x+1][y] = 1;
            push(x+1, y);
            foundPath = 1;
        }
        else if(y-1 >= 0 && maze[x][y-1] == 0 && !visited[x][y-1]) {
            // Check left
            visited[x][y-1] = 1;
            push(x, y-1);
            foundPath = 1;
        }
        else if(y+1 < COLS && maze[x][y+1] == 0 && !visited[x][y+1]) {
            // Check right
            visited[x][y+1] = 1;
            push(x, y+1);
            foundPath = 1;
        }

        if(!foundPath) {
            // Dead end reached
            pop();
        }
    }
}

int main() {
    generateMaze();
    printf("Generated Maze:\n");
    printMaze();

    solveMaze();
    printf("\n\nSolved Maze:\n");
    printMaze();

    return 0;
}
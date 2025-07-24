//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 25
#define MAX_COLS 25

typedef struct {
    int x;
    int y;
} Cell;

void initializeMaze(int maze[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 1; //assume all cells are walls
        }
    }
}

void printMaze(int maze[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 1) {
                printf("#"); //print wall
            } else {
                printf(" "); //print path
            }
        }
        printf("\n");
    }
}

int canMove(int maze[][MAX_COLS], int x, int y, int rows, int cols) {
    if (x < 0 || x >= rows || y < 0 || y >= cols || maze[x][y] == 0) {
        return 0; //out of bounds or visited cell
    }
    return 1;
}

int hasUnvisitedNeighbors(int maze[][MAX_COLS], int x, int y, int rows, int cols) {
    if (canMove(maze, x-1, y, rows, cols) || canMove(maze, x+1, y, rows, cols) ||
        canMove(maze, x, y-1, rows, cols) || canMove(maze, x, y+1, rows, cols)) {
            return 1; //has unvisited neighbor
        }
    return 0;
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generateMaze(int maze[][MAX_COLS], int rows, int cols) {
    Cell stack[MAX_ROWS*MAX_COLS];
    int top = -1;
    
    //randomly select starting cell
    srand(time(NULL));
    int startX = rand() % rows;
    int startY = rand() % cols;
    
    maze[startX][startY] = 0; //mark as path
    top++;
    stack[top].x = startX;
    stack[top].y = startY;
    
    while (top >= 0) {
        shuffle(&stack[0].x, top+1); //shuffle the stack
        
        Cell curr = stack[top];
        if (hasUnvisitedNeighbors(maze, curr.x, curr.y, rows, cols)) {
            int neighbors[4][2] = {{curr.x-1, curr.y}, {curr.x+1, curr.y},
                                    {curr.x, curr.y-1}, {curr.x, curr.y+1}};
            int numNeighbors = 4;
            for (int i = 0; i < 4; i++) {
                if (!canMove(maze, neighbors[i][0], neighbors[i][1], rows, cols)) {
                    numNeighbors--;
                    continue;
                }
                if (hasUnvisitedNeighbors(maze, neighbors[i][0], neighbors[i][1], rows, cols)) {
                    numNeighbors--;
                    continue;
                }
            }
            if (numNeighbors > 0) {
                int r;
                do {
                    r = rand() % 4;
                } while (!canMove(maze, neighbors[r][0], neighbors[r][1], rows, cols) ||
                            hasUnvisitedNeighbors(maze, neighbors[r][0], neighbors[r][1], rows, cols));
                            
                //knock down wall between current cell and selected neighbor
                if (r == 0) {
                    maze[curr.x-1][curr.y] = 0;
                } else if (r == 1) {
                    maze[curr.x+1][curr.y] = 0;
                } else if (r == 2) {
                    maze[curr.x][curr.y-1] = 0;
                } else {
                    maze[curr.x][curr.y+1] = 0;
                }
                
                //mark selected neighbor as path and add to stack
                top++;
                stack[top].x = neighbors[r][0];
                stack[top].y = neighbors[r][1];
                maze[stack[top].x][stack[top].y] = 0;
            } else {
                top--; //backtrack
            }
        } else {
            top--; //backtrack
        }
    }
}

int main() {
    int maze[MAX_ROWS][MAX_COLS];
    initializeMaze(maze, MAX_ROWS, MAX_COLS);
    generateMaze(maze, MAX_ROWS, MAX_COLS);
    printMaze(maze, MAX_ROWS, MAX_COLS);
    return 0;
}
//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

enum CellState {EMPTY, WALL, PATH};

struct Maze {
    int rows; // number of rows in the maze
    int cols; // number of columns in the maze
    enum CellState cells[ROWS][COLS]; // each cell in the maze
};

void printMaze(struct Maze m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (m.cells[i][j] == EMPTY) {
                printf(" ");
            }
            else if (m.cells[i][j] == WALL) {
                printf("#");
            }
            else if (m.cells[i][j] == PATH) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // create a maze with all walls
    struct Maze maze = {ROWS, COLS};
    for (int i = 0; i < maze.rows; i++) {
        for (int j = 0; j < maze.cols; j++) {
            maze.cells[i][j] = WALL;
        }
    }
    
    // create starting and ending points
    int startX = rand() % COLS;
    int startY = rand() % ROWS;
    int endX = rand() % COLS;
    int endY = rand() % ROWS;
    maze.cells[startY][startX] = EMPTY;
    maze.cells[endY][endX] = EMPTY;
    
    // randomly generate paths through the maze
    int currentX = startX;
    int currentY = startY;
    while (currentX != endX || currentY != endY) {
        maze.cells[currentY][currentX] = EMPTY;
        int direction = rand() % 4; // 0 = up, 1 = right, 2 = down, 3 = left
        switch (direction) {
            case 0: // up
                if (currentY > 0 && maze.cells[currentY-1][currentX] == WALL) {
                    currentY--;
                }
                break;
            case 1: // right
                if (currentX < maze.cols-1 && maze.cells[currentY][currentX+1] == WALL) {
                    currentX++;
                }
                break;
            case 2: // down
                if (currentY < maze.rows-1 && maze.cells[currentY+1][currentX] == WALL) {
                    currentY++;
                }
                break;
            case 3: // left
                if (currentX > 0 && maze.cells[currentY][currentX-1] == WALL) {
                    currentX--;
                }
                break;
        }
    }
    
    // print the maze
    printMaze(maze);
    
    return 0;
}
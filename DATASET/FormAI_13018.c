//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void createMaze(int maze[ROW][COL]);
void printMaze(int maze[ROW][COL]);
void generateMaze(int maze[ROW][COL], int row, int col);
void traverseMaze(int maze[ROW][COL], int row, int col);

int main() {
    int maze[ROW][COL];
    createMaze(maze);
    printMaze(maze);
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void createMaze(int maze[ROW][COL]) {
    srand(time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    maze[0][0] = 0;
    maze[ROW-1][COL-1] = 0;
}

void printMaze(int maze[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generateMaze(int maze[ROW][COL], int row, int col) {
    maze[row][col] = 0;
    if(row == ROW-1 && col == COL-1) {
        return;
    }
    while(1) {
        int direction = rand() % 4; //0: Up, 1: Right, 2: Down, 3: Left
        if(direction == 0 && row > 0 && maze[row-1][col]) { //Up
            maze[row-1][col] = 0;
            generateMaze(maze, row-1, col);
        } else if(direction == 1 && col < COL-1 && maze[row][col+1]) { //Right
            maze[row][col+1] = 0;
            generateMaze(maze, row, col+1);
        } else if(direction == 2 && row < ROW-1 && maze[row+1][col]) { //Down
            maze[row+1][col] = 0;
            generateMaze(maze, row+1, col);
        } else if(direction == 3 && col > 0 && maze[row][col-1]) { //Left
            maze[row][col-1] = 0;
            generateMaze(maze, row, col-1);
        }
        if(maze[ROW-1][COL-1] == 0) {
            return;
        }
    }
}

void traverseMaze(int maze[ROW][COL], int row, int col) {
    if(row == ROW-1 && col == COL-1) {
        return;
    }
    if(row < ROW-1 && maze[row+1][col] == 0) { //Down
        printf("(%d, %d) -> ", row+1, col+1);
        traverseMaze(maze, row+1, col);
    } else if(col < COL-1 && maze[row][col+1] == 0) { //Right
        printf("(%d, %d) -> ", row+1, col+1);
        traverseMaze(maze, row, col+1);
    } else if(row > 0 && maze[row-1][col] == 0) { //Up
        printf("(%d, %d) -> ", row-1, col+1);
        traverseMaze(maze, row-1, col);
    } else if(col > 0 && maze[row][col-1] == 0) { //Left
        printf("(%d, %d) -> ", row+1, col-1);
        traverseMaze(maze, row, col-1);
    }
}
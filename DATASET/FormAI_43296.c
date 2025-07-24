//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define WALL '#'
#define PATH ' '
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

void printMaze(char maze[ROW][COL]) {
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROW][COL]) {
    //Fill with all walls
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            maze[i][j] = WALL;
        }
    }

    //Generate random paths
    srand(time(NULL));
    int row = START_ROW;
    int col = START_COL;
    maze[row][col] = PATH;

    while(row != END_ROW || col != END_COL) {
        int dir = rand() % 4; //0:left, 1:up, 2:right, 3:down

        if(dir == 0 && col > 0 && maze[row][col-1] == WALL) {
            col--;
            maze[row][col] = PATH;

        } else if(dir == 1 && row > 0 && maze[row-1][col] == WALL) {
            row--;
            maze[row][col] = PATH;

        } else if(dir == 2 && col < COL-1 && maze[row][col+1] == WALL) {
            col++;
            maze[row][col] = PATH;

        } else if(dir == 3 && row < ROW-1 && maze[row+1][col] == WALL) {
            row++;
            maze[row][col] = PATH;

        }
    }
}

int main() {
    char maze[ROW][COL];

    generateMaze(maze);

    printMaze(maze);

    return 0;
}
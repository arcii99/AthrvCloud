//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 50

void printMaze(char maze[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROW][COL]) {
    srand(time(0));
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            int r = rand()%5;
            if(r == 0) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }
}

int findPath(char maze[ROW][COL], int row, int col) {
    if(row<0 || row>=ROW || col<0 || col>=COL) {
        return 0;
    }

    if(maze[row][col] == '#') {
        return 0;
    }

    if(maze[row][col] == 'X') {
        return 1;
    }

    maze[row][col] = '#';

    if(findPath(maze, row-1, col) == 1) {
        return 1;
    }
    if(findPath(maze, row, col+1) == 1) {
        return 1;
    }
    if(findPath(maze, row+1, col) == 1) {
        return 1;
    }
    if(findPath(maze, row, col-1) == 1) {
        return 1;
    }

    return 0;
}

int main() {
    char maze[ROW][COL];

    printf("Generating a maze...\n");
    generateMaze(maze);
    maze[0][0] = ' ';
    maze[ROW-1][COL-1] = 'X';

    printf("Maze generated: \n");
    printMaze(maze);

    printf("Finding a path through the maze...\n");
    if(findPath(maze, 0, 0) == 1) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    printf("Maze with path: \n");
    printMaze(maze);

    return 0;
}
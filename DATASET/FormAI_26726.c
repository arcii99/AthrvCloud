//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

void generateMaze(char maze[ROW][COL]) {
    srand(time(NULL));
    int i, j;

    // Fill the maze with walls
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = '#';
        }
    }

    // Set a random starting point for the maze
    int startX = rand() % ROW;
    int startY = rand() % COL;

    // Carve the path from the starting point
    maze[startX][startY] = ' ';
    int currX = startX, currY = startY;
    int endX, endY;
    while (1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Move up
                if (currX > 1 && maze[currX-2][currY] == '#') {
                    maze[currX-1][currY] = ' ';
                    maze[currX-2][currY] = ' ';
                    currX -= 2;
                }
                break;
            case 1: // Move right
                if (currY < COL - 2 && maze[currX][currY+2] == '#') {
                    maze[currX][currY+1] = ' ';
                    maze[currX][currY+2] = ' ';
                    currY += 2;
                }
                break;
            case 2: // Move down
                if (currX < ROW - 2 && maze[currX+2][currY] == '#') {
                    maze[currX+1][currY] = ' ';
                    maze[currX+2][currY] = ' ';
                    currX += 2;
                }
                break;
            case 3: // Move left
                if (currY > 1 && maze[currX][currY-2] == '#') {
                    maze[currX][currY-1] = ' ';
                    maze[currX][currY-2] = ' ';
                    currY -= 2;
                }
                break;
        }

        // If we are at the edge of the maze, set the end coordinates
        if (currX == 0 || currX == ROW - 1 || currY == 0 || currY == COL - 1) {
            endX = currX;
            endY = currY;
            break;
        }
    }

    // Set the end point of the maze
    maze[endX][endY] = '$';
}

void printMaze(char maze[ROW][COL]) {
    int i, j;

    // Print the maze
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}
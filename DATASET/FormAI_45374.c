//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 20
#define WALL 1
#define PATH 0
#define START 'S'
#define END 'E'
#define VISITED 'X'

int maze[ROW][COL] = { // defining a maze with walls and open spaces
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1},
    {1,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,1,0},
    {1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,1},
    {1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1},
    {1,0,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void printMaze(void) { // function to print the maze with its current status
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            switch (maze[i][j]) {
                case START:
                    printf("\033[1;32m%c\033[0m", START);
                    break;
                case END:
                    printf("\033[1;31m%c\033[0m", END);
                    break;
                case VISITED:
                    printf("\033[1;34m%c\033[0m", VISITED);
                    break;
                case WALL:
                    printf("\033[1;37m%c\033[0m", WALL);
                    break;
                default:
                    printf("%d", PATH);
            }
        }
        printf("\n");
    }
}

void markVisited(int row, int col) { // function to mark the path that is visited
    maze[row][col] = VISITED;
}

int findExit(int row, int col) { // function to find the exit path
    if (maze[row][col] == END) { // exit has been found
        return 1;
    } else if (maze[row][col] == WALL || maze[row][col] == VISITED) { // hit a wall or visited already
        return 0;
    }

    markVisited(row, col); // make current position as visited

    // Try to find the exit in all 4 directions; up, down, left and right
    if (findExit(row - 1, col) == 1) { // up
        return 1;
    } else if (findExit(row + 1, col) == 1) { // down
        return 1;
    } else if (findExit(row, col - 1) == 1) { // left
        return 1;
    } else if (findExit(row, col + 1) == 1) { // right
        return 1;
    }

    return 0;
}

int main() {
    int startRow, startCol;

    // Loop through the maze to find the starting position
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == START) {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    printf("Welcome to the maze!\n\n");
    printf("Starting position: [%d, %d]\n", startRow, startCol);

    if (findExit(startRow, startCol) == 1) {
        printf("\nExit found!\n\n");
    } else {
        printf("\nNo exit available :(\n\n");
    }

    printMaze();

    printf("\n");

    return 0;
}
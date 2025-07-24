//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void fillMaze() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void findRoute(int xPos, int yPos) {
    if(xPos < 0 || xPos >= ROWS || yPos < 0 || yPos >= COLS) {
        return;
    }
    if(maze[xPos][yPos] == 0) {
        return;
    }
    maze[xPos][yPos] = 0;
    if(xPos == ROWS-1 && yPos == COLS-1) {
        printf("You have reached the end of the maze! Congratulations!\n");
        return;
    }
    findRoute(xPos-1, yPos);
    findRoute(xPos, yPos+1);
    findRoute(xPos+1, yPos);
    findRoute(xPos, yPos-1);
}

int main() {
    printf("Welcome to the Maze Route Finder Program!\n");
    printf("Generating random maze...\n");
    fillMaze();
    printf("Maze has been generated!\n");
    printf("Here is your maze:\n");
    printMaze();
    printf("Finding route...\n");
    findRoute(0, 0);
    printf("Route has been found!\n");
    printf("Here is your maze with the route marked:\n");
    printMaze();
    return 0;
}
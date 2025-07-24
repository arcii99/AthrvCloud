//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '

void printMaze(char maze[][50], int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initializing the maze with walls
    char maze[50][50];
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            maze[i][j] = WALL;
        }
    }

    srand(time(0)); // Seed the random function with time

    // Creating a path through the maze
    int r = 1, c = 1;
    maze[r][c] = PATH;
    while(r != 48 || c != 48) {
        int n = rand() % 4; // Generate a random number between 0 and 3
        switch(n) {
            case 0: // Move up
                if(r-2 > 0 && maze[r-2][c] == WALL) {
                    maze[r-1][c] = PATH;
                    maze[r-2][c] = PATH;
                    r -= 2;
                }
                break;
            case 1: // Move down
                if(r+2 < 50 && maze[r+2][c] == WALL) {
                    maze[r+1][c] = PATH;
                    maze[r+2][c] = PATH;
                    r += 2;
                }
                break;
            case 2: // Move left
                if(c-2 > 0 && maze[r][c-2] == WALL) {
                    maze[r][c-1] = PATH;
                    maze[r][c-2] = PATH;
                    c -= 2;
                }
                break;
            case 3: // Move right
                if(c+2 < 50 && maze[r][c+2] == WALL) {
                    maze[r][c+1] = PATH;
                    maze[r][c+2] = PATH;
                    c += 2;
                }
                break;
        }
    }

    printMaze(maze, 50, 50); // Print the maze
    return 0;
}
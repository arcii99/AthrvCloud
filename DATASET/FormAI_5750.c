//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(char maze[][COLS])
{
    // Set all cells to be walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Set starting position as an empty space
    int startX = rand() % ROWS;
    int startY = rand() % COLS;
    maze[startX][startY] = ' ';

    // Create a maze by removing walls randomly
    int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int numDirs = 4;
    int x = startX, y = startY;
    while (numDirs > 0) {
        int randDir = rand() % numDirs;
        int deltaX = dirs[randDir][0];
        int deltaY = dirs[randDir][1];
        int newX = x + deltaX;
        int newY = y + deltaY;

        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == '#') {
            maze[newX][newY] = ' ';
            x = newX;
            y = newY;
        }

        // Remove the chosen direction from the list of directions
        dirs[randDir][0] = dirs[numDirs - 1][0];
        dirs[randDir][1] = dirs[numDirs - 1][1];
        numDirs--;
    }
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate the maze
    char maze[ROWS][COLS];
    generateMaze(maze);

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

enum direction { UP, DOWN, LEFT, RIGHT };

void generateMaze(int maze[ROWS][COLS], int x, int y, int visited[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    int visited[ROWS][COLS] = {0};
    srand(time(NULL)); // Seed random number generator

    generateMaze(maze, 0, 0, visited);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[ROWS][COLS], int x, int y, int visited[ROWS][COLS]) {
    visited[x][y] = 1; // Mark current cell as visited
    int directions[4] = { UP, DOWN, LEFT, RIGHT };
    int temp;

    // Shuffle array of directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Check each direction
    for (int i = 0; i < 4; i++) {
        switch (directions[i]) {
            case UP:
                if (x - 1 >= 0 && !visited[x - 1][y]) { // Check if cell above has not been visited
                    maze[x][y] |= 1 << UP; // Mark current cell as connected to upper cell
                    maze[x - 1][y] |= 1 << DOWN; // Mark upper cell as connected to current cell
                    generateMaze(maze, x - 1, y, visited); // Recursive call for upper cell
                }
                break;
            case DOWN:
                if (x + 1 < ROWS && !visited[x + 1][y]) { // Check if cell below has not been visited
                    maze[x][y] |= 1 << DOWN; // Mark current cell as connected to lower cell
                    maze[x + 1][y] |= 1 << UP; // Mark lower cell as connected to current cell
                    generateMaze(maze, x + 1, y, visited); // Recursive call for lower cell
                }
                break;
            case LEFT:
                if (y - 1 >= 0 && !visited[x][y - 1]) { // Check if cell to the left has not been visited
                    maze[x][y] |= 1 << LEFT; // Mark current cell as connected to left cell
                    maze[x][y - 1] |= 1 << RIGHT; // Mark left cell as connected to current cell
                    generateMaze(maze, x, y - 1, visited); // Recursive call for left cell
                }
                break;
            case RIGHT:
                if (y + 1 < COLS && !visited[x][y + 1]) { // Check if cell to the right has not been visited
                    maze[x][y] |= 1 << RIGHT; // Mark current cell as connected to right cell
                    maze[x][y + 1] |= 1 << LEFT; // Mark right cell as connected to current cell
                    generateMaze(maze, x, y + 1, visited); // Recursive call for right cell
                }
                break;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((maze[i][j] & (1 << UP)) == 0)
                printf("+---"); // If not connected to upper cell, print "+---"
            else
                printf("+   "); // If connected to upper cell, print "+   "

            if ((maze[i][j] & (1 << RIGHT)) == 0)
                printf("|"); // If not connected to right cell, print "|"
            else
                printf(" "); // If connected to right cell, print " "

            if (j == COLS - 1)
                printf("+\n"); // If last column, print closing "+"
        }

        if (i == ROWS - 1) { // Print bottom row
            for (int j = 0; j < COLS; j++)
                printf("+---");

            printf("+\n");
        }
        else {
            for (int j = 0; j < COLS; j++) {
                if ((maze[i][j] & (1 << DOWN)) == 0)
                    printf("+---"); // If not connected to lower cell, print "+---"
                else
                    printf("+   "); // If connected to lower cell, print "+   "
            }

            printf("+\n"); // Print closing "+"
        }
    }
}
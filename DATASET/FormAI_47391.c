//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void displayMaze(char maze[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[ROWS][COLS];
    int i, j;

    srand(time(NULL));

    // Fill the maze with walls and paths
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = '#'; // Border walls
            } else if (i % 2 == 0 && j % 2 == 0) {
                maze[i][j] = '#'; // Inner walls
            } else {
                maze[i][j] = ' '; // Paths
            }
        }
    }

    // Generate the maze
    int r, c;
    int nbr = 0; // Number of neighbors
    int rnbr[4]; // Random neighbors indexes

    // Start position
    r = 1;
    c = 1;
    maze[r][c] = 'S';

    do {
        nbr = 0;

        // Find the neighbors indexes
        if (maze[r - 2][c] == ' ') {
            rnbr[nbr] = 0;
            nbr++;
        }
        if (maze[r][c - 2] == ' ') {
            rnbr[nbr] = 1;
            nbr++;
        }
        if (maze[r + 2][c] == ' ') {
            rnbr[nbr] = 2;
            nbr++;
        }
        if (maze[r][c + 2] == ' ') {
            rnbr[nbr] = 3;
            nbr++;
        }

        // If there are neighbors
        if (nbr != 0) {
            int random_nbr = rnbr[rand() % nbr];

            switch (random_nbr) {
                case 0: // Top neighbor
                    maze[r - 2][c] = ' ';
                    maze[r - 1][c] = ' ';
                    r -= 2;
                    break;
                case 1: // Left neighbor
                    maze[r][c - 2] = ' ';
                    maze[r][c - 1] = ' ';
                    c -= 2;
                    break;
                case 2: // Bottom neighbor
                    maze[r + 2][c] = ' ';
                    maze[r + 1][c] = ' ';
                    r += 2;
                    break;
                case 3: // Right neighbor
                    maze[r][c + 2] = ' ';
                    maze[r][c + 1] = ' ';
                    c += 2;
                    break;
            }
        }
    } while (nbr != 0||maze[r]>=ROWS-3||maze[c]>=COLS-3);

    // End position
    maze[r][c] = 'E';

    displayMaze(maze);

    return 0;
}
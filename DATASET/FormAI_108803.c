//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main() {
    srand(time(NULL));
    int maze[SIZE][SIZE];

    // Fill the maze with random 0's and 1's
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    // Choose a random starting position
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    maze[x][y] = 2;  // Mark the starting position

    // Loop until we reach the end of the maze
    while (maze[x][y] != 3) {
        // Check if there's a path to the right
        if (y + 1 < SIZE && maze[x][y + 1] == 1) {
            y++;
            maze[x][y] = 2;  // Mark our new position
        }
        // Check if there's a path down
        else if (x + 1 < SIZE && maze[x + 1][y] == 1) {
            x++;
            maze[x][y] = 2;  // Mark our new position
        }
        // Check if there's a path to the left
        else if (y - 1 >= 0 && maze[x][y - 1] == 1) {
            y--;
            maze[x][y] = 2;  // Mark our new position
        }
        // Check if there's a path up
        else if (x - 1 >= 0 && maze[x - 1][y] == 1) {
            x--;
            maze[x][y] = 2;  // Mark our new position
        }
        // If there are no paths, backtrack to find a new path
        else {
            // Find the most recent marked position
            for (int i = x - 1; i >= 0; i--) {
                if (maze[i][y] == 2) {
                    x = i;
                    break;
                }
            }
            for (int j = y - 1; j >= 0; j--) {
                if (maze[x][j] == 2) {
                    y = j;
                    break;
                }
            }
        }
    }

    // Print the maze
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("#");
            }
            else if (maze[i][j] == 1) {
                printf(" ");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}
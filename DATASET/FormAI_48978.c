//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 0, y = 0;
    int row, col;
    int i, j;
    char matrix[20][20];
    char input;

    // Initialize the matrix with blank spaces
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Set up the initial position of the robot
    matrix[x][y] = 'R';

    // Print out the matrix
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Move the robot based on user input
    while (1) {
        printf("Enter a direction (u/d/l/r): ");
        scanf(" %c", &input);
        switch (input) {
            case 'u':
                if (x > 0) {
                    matrix[x][y] = ' ';
                    x--;
                    matrix[x][y] = 'R';
                }
                break;
            case 'd':
                if (x < 19) {
                    matrix[x][y] = ' ';
                    x++;
                    matrix[x][y] = 'R';
                }
                break;
            case 'l':
                if (y > 0) {
                    matrix[x][y] = ' ';
                    y--;
                    matrix[x][y] = 'R';
                }
                break;
            case 'r':
                if (y < 19) {
                    matrix[x][y] = ' ';
                    y++;
                    matrix[x][y] = 'R';
                }
                break;
            default:
                printf("Invalid direction.\n");
        }

        // Clear the screen and print out the updated matrix
        system("clear");
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 20; j++) {
                printf("%c ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main(void) {
    char grid[ROWS][COLS];
    int row, col, row_dir, col_dir, steps;
    
    // Initialize grid with empty spaces
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            grid[row][col] = ' ';
        }
    }
    
    // Set starting position
    row = rand() % ROWS;
    col = rand() % COLS;
    
    // Set direction and number of steps
    row_dir = col_dir = steps = 1;
    
    // Game loop
    while (1) {
        // Print grid
        system("clear"); // Clear console on Unix/Linux
        printf(" use 'a' to turn left, 'd' to turn right, 'w' to move forward and 's' to move backward \n");
        printf("+----------+\n");
        for (row = 0; row < ROWS; row++) {
            printf("|");
            for (col = 0; col < COLS; col++) {
                if (row == ROWS / 2 && col == COLS / 2) {
                    printf("%c", 'X'); // Print player position
                } else {
                    printf("%c", grid[row][col]);
                }
            }
            printf("|\n");
        }
        printf("+----------+\n");
        
        // Get user input
        char input;
        scanf(" %c", &input);
        
        // Process user input
        switch (input) {
            case 'a': // Turn left
                if (row_dir == 0) {
                    row_dir = col_dir;
                    col_dir = 0;
                } else {
                    col_dir = -row_dir;
                    row_dir = 0;
                }
                break;
            case 'd': // Turn right
                if (row_dir == 0) {
                    row_dir = -col_dir;
                    col_dir = 0;
                } else {
                    col_dir = row_dir;
                    row_dir = 0;
                }
                break;
            case 'w': // Move forward
                row += row_dir;
                col += col_dir;
                if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                    printf("You hit the wall and lost the game!\n");
                    return 0;
                }
                // Check if already visited
                if (grid[row][col] != ' ') {
                    printf("You hit your path and lost the game!\n");
                    return 0;
                }
                // Mark as visited
                grid[row][col] = '*';
                steps++;
                break;
            case 's': // Move backward
                row -= row_dir;
                col -= col_dir;
                if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                    printf("You hit the wall and lost the game!\n");
                    return 0;
                }
                // Check if already visited
                if (grid[row][col] != ' ') {
                    printf("You hit your path and lost the game!\n");
                    return 0;
                }
                // Mark as visited
                grid[row][col] = '*';
                steps++;
                break;
            default:
                break;
        }
        
        // Check if game over
        if (steps == ROWS * COLS) {
            printf("You finished the game in %d steps! Congratulations!\n", steps);
            return 0;
        }
    }
}
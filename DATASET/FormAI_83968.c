//FormAI DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int main() {
    // Initialize the board
    int board[HEIGHT][WIDTH];
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    // Run the game of life
    int generation = 1;
    while (1) {
        // Print the generation number
        printf("\n Generation %d: \n\n", generation);
        
        // Print the board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == 1) {
                    printf(" * ");
                }
                else {
                    printf(" . ");
                }
            }
            printf("\n");
        }
        
        // Generate the next board
        int next_board[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                // Count the number of live neighbors
                int live_neighbors = 0;
                for (int i2 = i-1; i2 <= i+1; i2++) {
                    for (int j2 = j-1; j2 <= j+1; j2++) {
                        if (i2 == i && j2 == j) {
                            continue;
                        }
                        if (i2 < 0 || i2 >= HEIGHT || j2 < 0 || j2 >= WIDTH) {
                            continue;
                        }
                        if (board[i2][j2] == 1) {
                            live_neighbors++;
                        }
                    }
                }
                
                // Apply the rules of the game
                if (board[i][j] == 1) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        next_board[i][j] = 1;
                    }
                    else {
                        next_board[i][j] = 0;
                    }
                }
                else {
                    if (live_neighbors == 3) {
                        next_board[i][j] = 1;
                    }
                    else {
                        next_board[i][j] = 0;
                    }
                }
            }
        }
        
        // Update the board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                board[i][j] = next_board[i][j];
            }
        }
        
        // Sleep for 1 second
        printf("\n");
        for (int i = 0; i < 40; i++) {
            printf("=");
        }
        printf("\n");
        sleep(1);
        generation++;
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// Initialize the grid randomly
void init_grid(int grid[][WIDTH]) {
    srand(time(NULL));

    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            grid[row][col] = rand() % 2;
        }
    }
}

// Display the grid on the console
void display_grid(int grid[][WIDTH]) {
    printf("\033[2J\033[1;1H"); // Clear the console
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            if(grid[row][col] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Helper function to count the number of live neighbors
int count_neighbors(int grid[][WIDTH], int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;

            if(neighbor_row >= HEIGHT) {
                neighbor_row = 0;
            } else if(neighbor_row < 0) {
                neighbor_row = HEIGHT - 1;
            }

            if(neighbor_col >= WIDTH) {
                neighbor_col = 0;
            } else if(neighbor_col < 0) {
                neighbor_col = WIDTH - 1;
            }

            count += grid[neighbor_row][neighbor_col];
        }
    }

    count -= grid[row][col];
    return count;
}

// Update the grid based on the rules of the game
void update_grid(int grid[][WIDTH]) {
    int new_grid[HEIGHT][WIDTH];

    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            int neighbors = count_neighbors(grid, row, col);

            if(grid[row][col] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[row][col] = 0;
            } else if(grid[row][col] == 0 && neighbors == 3) {
                new_grid[row][col] = 1;
            } else {
                new_grid[row][col] = grid[row][col];
            }
        }
    }

    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }
}

int main() {
    int grid[HEIGHT][WIDTH];

    init_grid(grid);

    while(1) {
        display_grid(grid);
        update_grid(grid);
        usleep(100000); // Sleep for 100 milliseconds
    }

    return 0;
}
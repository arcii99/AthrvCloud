//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

int main() {
  int grid[ROWS][COLS] = {0};
  int next_grid[ROWS][COLS] = {0};
  
  // Initialize Grid
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      int rand_num = (int) rand() % 2;
      grid[i][j] = rand_num;
    }
  }

  // Game Loop
  while(1) {
    // Print Current Grid State
    printf("\033[2J"); // Clear screen
    for(int i=0; i<ROWS; i++) {
      for(int j=0; j<COLS; j++) {
        if(grid[i][j] == 0) {
          printf("-");
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
    sleep(1); // Sleep for 1 second

    // Calculate Next Grid State
    for(int i=0; i<ROWS; i++) {
      for(int j=0; j<COLS; j++) {
        int neighbors = 0;
        for(int row=i-1; row<i+2; row++) {
          for(int col=j-1; col<j+2; col++) {
            if(row == i && col == j) {
              continue; // Skip self
            }
            if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
              continue; // Out of bounds
            }
            if(grid[row][col] == 1) {
              neighbors++;
            }
          }
        }
        // Apply Game of Life Rules
        if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
          next_grid[i][j] = 0;
        } else if(grid[i][j] == 0 && neighbors == 3) {
          next_grid[i][j] = 1;
        } else {
          next_grid[i][j] = grid[i][j];
        }
      }
    }

    // Update Grid
    for(int i=0; i<ROWS; i++) {
      for(int j=0; j<COLS; j++) {
        grid[i][j] = next_grid[i][j];
      }
    }
  }

  return 0;
}
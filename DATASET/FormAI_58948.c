//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 50

int grid1[ROWS][COLS];  // initial grid
int grid2[ROWS][COLS];  // updated grid

// function to display grid
void display(int grid[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (grid[i][j] == 1) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

// function to simulate Game of Life rules
void update_grid(int grid1[][COLS], int grid2[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int sum = 0;
      int neighbors[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};  // 8 neighbors of current cell
      for (int k = 0; k < 8; k++) {
        int ni = i + neighbors[k][0];
        int nj = j + neighbors[k][1];
        if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && grid1[ni][nj] == 1) {  // check if neighbor is alive
          sum += 1;
        }
      }
      if (grid1[i][j] == 1) {  // for live cell
        if (sum < 2 || sum > 3) {
          grid2[i][j] = 0;  // rule #1 and #3 - death by underpopulation or overpopulation
        } else {
          grid2[i][j] = 1;  // rule #2 - survival
        }
      } else {  // for dead cell
        if (sum == 3) {
          grid2[i][j] = 1;  // rule #4 - birth by reproduction
        } else {
          grid2[i][j] = 0;
        }
      }
    }
  }
}

int main() {
  // initialize grid1 with random values
  srand(time(NULL));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid1[i][j] = rand() % 2;
    }
  }
  
  display(grid1);
  
  // simulate Game of Life for 100 generations
  for (int g = 1; g <= 100; g++) {
    printf("Generation %d:\n", g);
    update_grid(grid1, grid2);
    display(grid2);
    // copy the updated grid to the initial grid for the next generation
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        grid1[i][j] = grid2[i][j];
      }
    }
    printf("\n");
  }
  
  return 0;
}
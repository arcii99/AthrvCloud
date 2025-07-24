//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>

// This program simulates the population of cells in a petri dish
// It starts with a single cell, and depending on how many neighbors it has, it may die or reproduce
// The program runs for 50 iterations, updating the cells' states each time

int main() {
  int n_iters = 50;
  int size = 20;
  int grid[size][size];
  
  // Start with a single cell in the middle of the dish
  grid[size/2][size/2] = 1;
  
  // Run the simulation for n_iters iterations
  for (int i = 0; i < n_iters; i++) {
    int new_grid[size][size];
    
    // Loop through each cell and determine its new state based on its neighbors
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        int n_neighbors = 0;
        
        // Count the number of neighboring cells that are alive
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;    // Don't count the cell itself
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;    // Don't count cells outside the grid
            if (grid[nx][ny]) n_neighbors++;
          }
        }
        
        // If the cell is currently alive, determine whether it survives or dies
        if (grid[x][y]) {
          if (n_neighbors == 2 || n_neighbors == 3) {
            new_grid[x][y] = 1;    // The cell survives
          } else {
            new_grid[x][y] = 0;    // The cell dies
          }
        } 
        
        // If the cell is currently dead, determine whether it is born
        else {
          if (n_neighbors == 3) {
            new_grid[x][y] = 1;    // A new cell is born
          } else {
            new_grid[x][y] = 0;    // The cell remains dead
          }
        }
      }
    }
    
    // Copy the new state of the cells to the grid
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        grid[x][y] = new_grid[x][y];
      }
    }
    
    // Print the current state of the grid
    printf("Iteration %d:\n", i+1);
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        printf("%c ", grid[x][y] ? '*' : ' ');
      }
      printf("\n");
    }
    printf("\n");
  }
  
  return 0;
}
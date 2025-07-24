//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int SIZE = 10; // define size of the grid
int grid[10][10] = { 0 }; // initialize grid with all zeros

void print_grid() { // function to print the grid
  for(int i=0; i<SIZE; i++) {
    for(int j=0; j<SIZE; j++) {
      printf("%d ", grid[i][j]); // prints each element in the grid followed by a space
    }
    printf("\n"); // prints a newline after each row
  }
}

bool percolate() { // function to determine if the grid percolates
  for(int j=0; j<SIZE; j++) { // loop through top row of grid
    if(grid[0][j] == 1) { // if there is a 1 at the top row
      for(int i=0; i<SIZE; i++) { // loop through bottom row of grid
        if(grid[SIZE-1][i] == 1) { // if there is a 1 at the bottom row
          return true; // the grid percolates
        }
      }
    }
  }
  return false; // the grid does not percolate
}

void simulate() { // function to simulate percolation
  srand(time(NULL)); // seed the random number generator

  int percent_open = 0; // percentage of open cells in grid
  int random_row = 0; // random row index
  int random_col = 0; // random column index

  while(!percolate()) { // loop until the grid percolates
    percent_open = 0; // reset percentage of open cells
    random_row = rand() % SIZE; // generate random row index
    random_col = rand() % SIZE; // generate random column index

    if(grid[random_row][random_col] == 0) { // if the cell is closed
      grid[random_row][random_col] = 1; // open the cell
    }

    for(int i=0; i<SIZE; i++) { // loop through grid to calculate percentage open
      for(int j=0; j<SIZE; j++) {
        if(grid[i][j] == 1) { // if the cell is open
          percent_open++; // increment percentage of open cells
        }
      }
    }

    printf("Percent Open: %d\n", (percent_open*100)/(SIZE*SIZE)); // print percentage of open cells
    print_grid(); // print the grid
    printf("----------------------------\n"); // print separator
  }
}

int main() {
  simulate(); // run the simulation
  return 0;
}
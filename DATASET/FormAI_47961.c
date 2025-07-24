//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to randomly open sites
int random_open(int n, int open_sites[]) {
  int random_site = rand() % n;
  while (open_sites[random_site] == 1) {
    random_site = rand() % n;
  }
  open_sites[random_site] = 1;
  return random_site;
}

int main() {
  srand(time(NULL)); //Initializes random seed

  int grid_size, num_of_open_sites;
  printf("Enter size of the grid: "); //Asking user for size of the grid
  scanf("%d", &grid_size);

  int grid[grid_size][grid_size], open_sites[grid_size*grid_size];
  for (int i=0; i<grid_size; i++) {
    for (int j=0; j<grid_size; j++) {
      grid[i][j] = 0; //Initializing all sites as closed
    }
  }
  for (int i=0; i<grid_size*grid_size; i++) {
    open_sites[i] = 0; //Initializing all sites as unopened
  }

  //Opening top row of sites
  for (int i=0; i<grid_size; i++) {
    open_sites[i] = 1;
  }
  num_of_open_sites = grid_size;

  //Loop to percolate the grid
  while (num_of_open_sites < grid_size*grid_size) {
    int random_site = random_open(grid_size*grid_size, open_sites);
    int row = random_site / grid_size;
    int col = random_site % grid_size;

    //Checking if adjacent sites are open and joining the cluster
    if (row > 0 && grid[row-1][col] == 1) {
      grid[row][col] = 1;
      num_of_open_sites++;
    }
    if (row < grid_size-1 && grid[row+1][col] == 1) {
      grid[row][col] = 1;
      num_of_open_sites++;
    }
    if (col > 0 && grid[row][col-1] == 1) {
      grid[row][col] = 1;
      num_of_open_sites++;
    }
    if (col < grid_size-1 && grid[row][col+1] == 1) {
      grid[row][col] = 1;
      num_of_open_sites++;
    }
  }

  //Checking if the grid percolates
  int percolates = 0;
  for (int i=0; i<grid_size; i++) {
    if (grid[grid_size-1][i] == 1) {
      percolates = 1;
      break;
    }
  }

  //Printing whether the grid percolates or not
  if (percolates == 1) {
    printf("Oh happy dagger, this grid percolates!\n");
  } else {
    printf("O brawling love, O loving hate, this grid does not percolate.\n");
  }

  return 0;
}
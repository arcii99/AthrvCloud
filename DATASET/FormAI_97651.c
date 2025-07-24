//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void percolate(int n, double p, int t) {
  int grid[n][n]; // create the grid
  srand(time(NULL)); // seed the random number generator
  
  // initialize the grid with filled or empty sites
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double r = (double) rand() / RAND_MAX; // generate a random number between 0 and 1
      grid[i][j] = (r < p) ? 1 : 0; // set the site to be filled or empty
    }
  }
  
  // print the initial grid
  printf("Initial Grid:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", grid[i][j] ? '#' : '.');
    }
    printf("\n");
  }
  
  // check if the grid percolates t times
  for (int k = 0; k < t; k++) {
    int visited[n][n]; // create a grid to track visited sites
    int top_reached = 0; // flag to check if the top row is connected to the bottom row
    
    // initialize the visited grid with zeros
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        visited[i][j] = 0;
      }
    }
    
    // recursive function to check if two sites are percolated
    void dfs(int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= n || !grid[x][y] || visited[x][y]) {
        return; // ignore sites outside the grid, empty sites, or visited sites
      }
      visited[x][y] = 1; // mark the site as visited
      if (x == n-1) {
        top_reached = 1; // the top row is connected to the bottom row
      }
      dfs(x-1, y); // check the site to the left
      dfs(x+1, y); // check the site to the right
      dfs(x, y-1); // check the site below
      dfs(x, y+1); // check the site above
    }
    
    // check if the grid percolates from each site in the top row
    for (int j = 0; j < n; j++) {
      if (grid[0][j]) {
        dfs(0, j); // start the DFS from the top row
        if (top_reached) {
          break; // no need to check the rest of the sites in the top row
        }
      }
    }
    
    // print the percolation result
    char result = top_reached ? 'Y' : 'N';
    printf("Simulation #%d: %c\n", k+1, result);
    
    // print the final grid
    printf("Final Grid:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%c", visited[i][j] ? 'o' : (grid[i][j] ? '#' : '.'));
      }
      printf("\n");
    }
  }
}

int main() {
  int n, t;
  double p;
  
  // read the input from a file
  FILE *fp = fopen("input.txt", "r");
  fscanf(fp, "%d %lf %d", &n, &p, &t); // assumes the input file is well-formatted
  fclose(fp);
  
  percolate(n, p, t); // run the percolation simulation
  
  return 0;
}
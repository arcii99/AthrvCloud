//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 50
#define P 0.6

int site[N][N]; // Site configuration

// Function to initialize the site configuration
void initSite() {
  srand(time(NULL)); // Seed the random number generator with time
  
  // Iterate over all sites in the grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double r = (double) rand() / (double) RAND_MAX; // Generate a random number between 0 and 1
      
      if (r <= P) {
        site[i][j] = 1; // Site is open
      } else {
        site[i][j] = 0; // Site is closed
      }
    }
  }
}

// Function to print the site configuration
void printSite() {
  printf("Site:\n");
  
  // Iterate over all sites in the grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (site[i][j] == 1) {
        printf("1 "); // Site is open
      } else {
        printf("0 "); // Site is closed
      }
    }
    
    printf("\n"); // Jump to next line after each row
  }
}

// Function to find the site clusters using depth-first search
void dfs(int i, int j, int cluster[N][N], int id) {
  // Check if site is out of bounds or not open
  if (i < 0 || i >= N || j < 0 || j >= N || site[i][j] != 1 || cluster[i][j] != 0) {
    return;
  }
  
  cluster[i][j] = id; // Assign site to current cluster
  
  dfs(i-1, j, cluster, id); // Search the site to the left
  dfs(i+1, j, cluster, id); // Search the site to the right
  dfs(i, j-1, cluster, id); // Search the site below
  dfs(i, j+1, cluster, id); // Search the site above
}

// Function to find and print the site clusters
void findClusters() {
  int cluster[N][N] = {{0}}; // Cluster ID for each site
  int id = 0; // Current cluster ID
  
  // Iterate over all sites in the grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (site[i][j] == 1 && cluster[i][j] == 0) { // Check if site is open and not already assigned to a cluster
        id += 1; // Increment current cluster ID
        dfs(i, j, cluster, id); // Find all sites in the cluster using depth-first search
      }
    }
  }
  
  printf("Clusters:\n");
  
  // Iterate over all cluster IDs
  for (int k = 1; k <= id; k++) {
    printf("Cluster #%d:\n", k);
    
    // Find and print all sites in the cluster
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (cluster[i][j] == k) {
          printf("(%d,%d) ", i, j);
        }
      }
    }
    
    printf("\n"); // Jump to next line after each cluster
  }
}

// Main function
int main() {
  initSite(); // Initialize the site configuration
  printSite(); // Print the site configuration
  findClusters(); // Find and print the site clusters
  
  return 0;
}
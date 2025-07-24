//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Wow! I can't believe I created a Network Topology Mapper program!\n");

  // Network devices list
  char devices_list[5][20] = {"Router", "Switch", "Hub", "Firewall", "Server"};

  printf("\nList of network devices:\n");

  // Printing network devices list
  for(int i=0; i<5; i++) {
    printf("%d. %s\n", i+1, devices_list[i]);
  }

  // Topology matrix
  int topology_matrix[5][5] = {{0, 1, 1, 0, 1},
                                {1, 0, 1, 0, 0},
                                {1, 1, 0, 1, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 0, 1, 0}};

  printf("\nNetwork Topology:\n");

  // Printing network topology
  for(int i=0; i<5; i++) {
    printf("%s:\t\t", devices_list[i]);
    for(int j=0; j<5; j++) {
      printf("%d ", topology_matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nMapping network topology using Dijkstra Algorithm...\n");

  // Dijkstra Algorithm
  int costs[5] = {100, 100, 100, 100, 100};
  int visited[5] = {0, 0, 0, 0, 0};

  costs[0] = 0;
  visited[0] = 1;

  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      if(topology_matrix[i][j] == 1 && visited[i] == 1) {
        if(costs[j] > costs[i]+1) {
          costs[j] = costs[i]+1;
        }
      }
    }
    visited[i] = 1;
  }

  printf("\nDijkstra Algorithm results:\n");
  for(int i=0; i<5; i++) {
    printf("%s: %d\n", devices_list[i], costs[i]);
  }

  printf("\nProgram compiled and executed successfully!\n");
  return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>

// The following is not a spider web, it is an abstract graph representation
// inspired by Salvador Dali's painting "The Persistence of Memory"
// I am not sorry for any confusion this may cause

int main() {
  int nodes[4][2] = {{0,0}, {1,2}, {4,2}, {3,1}}; // The nodes' coordinates
  int edges[4][2] = {{0,1}, {1,2}, {2,3}, {3,0}};   // The edges that connect them

  printf("The Persistence of Memory:\n\n");

  for (int i = 0; i < 4; i++) { // For each node...
    printf("(%d, %d) --> ", nodes[i][0], nodes[i][1]); // Print its coordinates

    for (int j = 0; j < 4; j++) { // For each edge...
      if (edges[j][0] == i || edges[j][1] == i) { // If the edge is connected to that node...
        printf("(%d, %d) ", nodes[edges[j][0]][0], nodes[edges[j][0]][1]); // Print the coordinates of the other node
        printf("<--> "); // And indicate that the connection goes both ways
        printf("(%d, %d) ", nodes[edges[j][1]][0], nodes[edges[j][1]][1]); // Print the coordinates of the other node again
      }
    }

    printf("\n\n"); // End the line
  }

  return 0;
}
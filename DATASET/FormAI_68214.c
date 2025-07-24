//FormAI DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>

int main() {
  int n = 7;
  int g[7][7] = {{0,1,1,0,0,0,0},
                 {1,0,0,1,1,0,0},
                 {1,0,0,0,0,1,1},
                 {0,1,0,0,0,1,0},
                 {0,1,0,0,0,1,0},
                 {0,0,1,1,1,0,0},
                 {0,0,1,0,0,0,0}};
  
  printf("Graph Representation:\n\n");

  for (int i = 0; i < n; i++) {
    printf("%d: ", i+1);

    for (int j = 0; j < n; j++) {
      if (g[i][j]) {
        printf("%d ", j+1);
      }
    }

    printf("\n");
  }

  return 0;
}
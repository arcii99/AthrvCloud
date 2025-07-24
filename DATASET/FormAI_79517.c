//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {

  int n = 5;

  for(int i = 1; i <= 2*n-1; i++) {
    for(int j = 1; j <= 2*n-1; j++) {
      if(i == 1 || i == 2*n-1 || j == 1 || j == 2*n-1) {
        printf("*");
      }
      else {
        int x = i-1;
        int y = j-1;

        int dist_x = x <= n-1 ? x : (2*n-2) - x;
        int dist_y = y <= n-1 ? y : (2*n-2) - y;

        int dist = dist_x <= dist_y ? dist_x : dist_y;

        printf("%d", dist);
      }
    }
    printf("\n");
  }

  return 0;
}
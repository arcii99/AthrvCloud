//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>

int main() {
  int row, col;
  
  // Top half of the pattern
  for(row = 1; row <= 6; row++) {
    for(col = 1; col <= row; col++) {
      printf("%d ", col);
    }
    printf("\n");
  }
  
  // Bottom half of the pattern
  for(row = 6; row >= 1; row--) {
    for(col = 1; col <= row; col++) {
      printf("%d ", col);
    }
    printf("\n");
  }
  
  return 0;
}

/*
Output:

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/
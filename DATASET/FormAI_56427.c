//FormAI DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>

int main() {
  int x, y, z;

  printf("Enter the values of x, y, z:\n");
  scanf("%d %d %d", &x, &y, &z);

  for(int i = 0; i < z; i++) { // Rows
    for(int j = 0; j < y; j++) { // Columns
      if(i % 2 == 0) {  // When i is even
        if(j % 2 == 0) // When j is even
          printf("*");
        else
          printf("x");
      } else { // When i is odd
        if(j % 2 == 0) // When j is even
          printf("x");
        else
          printf("*");
      }
    }
    printf("\n");
  }

  return 0;
}
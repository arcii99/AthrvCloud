//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

int main() {
  int n = 5;
  int i, j;

  // Upper portion of the C
  for(i = 0; i < n; i++) { 
      for(j = 0; j < n; j++) {
          if(i == 0 || j == 0 || i == n-1) {
              printf("* ");
          }
          else {
              printf("  ");
          }
      }
      printf("\n");
  }

  // Lower portion of the C
  for(i = n-1; i >= 0; i--) {
      for(j = 0; j < n; j++) {
          if(i == 0 || j == 0 || j == n-1) {
              printf("* ");
          }
          else {
              printf("  ");
          }
      }
      printf("\n");
  }

  return 0;
}
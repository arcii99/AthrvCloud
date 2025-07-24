//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main(void) {
  int i, j, k;
  int n = 9; // change n to adjust size of pattern
  
  // Print upper half of pattern
  for(i = n/2; i >= 1; i--) {
    for(j = i; j >= 1; j--) {
      printf("* ");
    }
    for(k = 1; k <= (n - 2*i); k++) {
      printf("  ");
    }
    for(j = i; j >= 1; j--) {
      printf("* ");
    }
    printf("\n");
  }
  
  // Print middle row
  for(i = 1; i <= n; i++) {
    printf("* ");
  }
  printf("\n");
  
  // Print lower half of pattern
  for(i = 1; i <= n/2; i++) {
    for(j = i; j >= 1; j--) {
      printf("* ");
    }
    for(k = 1; k <= (n - 2*i); k++) {
      printf("  ");
    }
    for(j = i; j >= 1; j--) {
      printf("* ");
    }
    printf("\n");
  }
  
  return 0;
}
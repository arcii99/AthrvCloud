//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

int main() {
  int n = 10;
  int i, j;
  
  for (i = n; i >= 1; i--) {
    for (j = i; j <= n; j++) {
      printf("* ");
    }
    
    for (j = i; j < n; j++) {
      printf("  ");
    }
    
    for (j = i; j <= n; j++) {
      printf("* ");
    }
    
    printf("\n");
  }
  
  for (i = 2; i <= n; i++) {
    for (j = i; j <= n; j++) {
      printf("* ");
    }
    
    for (j = 2; j <= i; j++) {
      printf("  ");
    }
    
    for (j = i; j <= n; j++) {
      printf("* ");
    }
    
    printf("\n");
  }
  
  return 0;
}
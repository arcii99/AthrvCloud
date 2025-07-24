//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {
  int n = 5;
  int i, j, k;
  
  for(i = 0; i < n; i++) {
    
    for(j = 0; j <= i; j++) {
      printf("*");
    }
    
    for(k = 0; k < (n-i-1); k++) {
      printf(" ");
    }
    
    for(j = 0; j <= i; j++) {
      printf("*");
    }
    
    printf("\n");
  }
  
  for(i = n-1; i >= 0; i--) {
    
    for(j = 0; j <= i; j++) {
      printf("*");
    }
    
    for(k = 0; k < (n-i-1); k++) {
      printf(" ");
    }
    
    for(j = 0; j <= i; j++) {
      printf("*");
    }
    
    printf("\n");
  }
  
  return 0;
}

/*
Output:
*    *
**  **
*****
**  **
*    *
*/
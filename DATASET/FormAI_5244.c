//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>

int main() {
  int n = 5;
  
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
        printf("%d ", i*j);
    }
    printf("\n");
  }

  for(int i=n-1; i>=1; i--) {
    for(int j=1; j<=i; j++) {
        printf("%d ", i*j);
    }
    printf("\n");
  }

  return 0;
}
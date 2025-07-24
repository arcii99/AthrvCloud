//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
  int n = 6;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(j == i || j == n-i+1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  for(int i=2; i<=n; i++) {
    for(int j=1; j<=n-i+1; j++) {
      printf(" ");
    }
    for(int k=1; k<=i; k++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
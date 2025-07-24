//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>

int main() {
  int i, j, k;
  int n = 8;

  for(i=0;i<n;i++) {
    for(j=n-i;j>1;j--)
      printf(" ");
    for(j=0;j<=i;j++)
      printf("* ");
    printf("\n");
  }
  
  for(i=n-1;i>=0;i--) {
    for(j=0;j<n-i;j++)
      printf(" ");
    for(j=0;j<=i;j++)
      printf("* ");
    printf("\n");
  }

  return 0;
}
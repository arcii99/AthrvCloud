//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int n, i, j, k;
  
  printf("Enter the length of the pattern: ");
  scanf("%d", &n);

  for(i=0; i<n; i++) {
    for(j=0; j<n-i-1; j++) {
      printf(" ");
    }
    for(k=0; k<i+1; k++) {
      printf("# ");
    }
    printf("\n");
  }

  for(i=n-1; i>0; i--) {
    for(j=0; j<n-i; j++) {
      printf(" ");
    }
    for(k=i; k>0; k--) {
      printf("# ");
    }
    printf("\n");
  }

  return 0;
}
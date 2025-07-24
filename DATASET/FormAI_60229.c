//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cryptic
#include<stdio.h>

int main() {
  int n = 5;
  int i, j, k, l;

  for(i=1; i<=n; i++) {
    for(j=1; j<=n-i+1; j++) {
      printf("*");
    }
    for(k=1; k<=2*i-2; k++) {
      printf(" ");
    }
    for(l=1; l<=n-i+1; l++) {
      printf("*");
    }
    printf("\n");
  }

  for(i=n-1; i>=1; i--) {
    for(j=1; j<=n-i+1; j++) {
      printf("*");
    }
    for(k=1; k<=2*i-2; k++) {
      printf(" ");
    }
    for(l=1; l<=n-i+1; l++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
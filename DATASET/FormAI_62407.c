//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {
  int i, j;

  printf("\n");
  for(i=1; i<=4; i++) {
    for(j=1; j<=i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("\n");
  for(i=1; i<=4; i++) {
    for(j=4; j>=i; j--) {
      printf("* ");
    }
    printf("\n");
  }

  printf("\n");
  for(i=1; i<=4; i++) {
    for(j=1; j<=4-i; j++) {
      printf("  ");
    }
    for(j=1; j<=i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("\n");
  for(i=1; i<=4; i++) {
    for(j=1; j<=4-i; j++) {
      printf("  ");
    }
    for(j=1; j<=i; j++) {
      printf("*   ");
    }
    printf("\n");
  }

  return 0;
}
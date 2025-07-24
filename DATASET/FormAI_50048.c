//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
  int n;
  
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  
  // top-half of the pattern
  for(int i = 1; i <= n; i++) {
    // print spaces
    for(int j = 1; j <= n - i; j++) {
      printf(" ");
    }
    // print stars
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // bottom-half of the pattern
  for(int i = n - 1; i >= 1; i--) {
    // print spaces
    for(int j = 1; j <= n - i; j++) {
      printf(" ");
    }
    // print stars
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
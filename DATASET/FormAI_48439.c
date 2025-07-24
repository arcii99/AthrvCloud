//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include <stdio.h>

int main() {
  int n = 5;

  for(int i = 1; i <= n; i++) {
    for(int j = n-i; j > 0; j--) {
      printf(" ");
    }
    for(int j = 1; j <= i; j++) {
      printf("*");
    }
    for(int j = 1; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
  for(int i = n-1; i >= 1; i--) {
    for(int j = n-i; j > 0; j--) {
      printf(" ");
    }
    for(int j = 1; j <= i; j++) {
      printf("*");
    }
    for(int j = 1; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
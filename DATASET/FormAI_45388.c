//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void recursive(int n) {
  if (n == 0) {
    printf("Blast Off!\n");
    return;
  }
  printf("%d\n", n);
  recursive(n - 1);
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("Invalid input!\n");
    return 1;
  }
  printf("Starting countdown...\n");
  recursive(n);
  return 0;
}
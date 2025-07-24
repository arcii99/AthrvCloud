//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

void countdown(int n) {
  if (n >= 0) {
      printf("%d...", n);
      countdown(n-1);
  } else {
      printf("Blastoff!\n");
  }
}

int main() {
  printf("Enter a non-negative integer: ");
  int n;
  scanf("%d", &n);
  countdown(n);
  return 0;
}
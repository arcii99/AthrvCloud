//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peaceful(int n) {
  if (n <= 0) {
    return;
  }
  printf("Peaceful\n");
  peaceful(n-1);
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  peaceful(num);
  return 0;
}
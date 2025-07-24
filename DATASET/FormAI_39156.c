//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

int count(int n) {
  if (n == 1) { // base case
    return 1;
  }

  if (n % 2 == 0) { // if n is even
    printf("n is even\n");
    return count(n / 2) + 1;
  } else { // if n is odd
    printf("n is odd\n");
    return count(3 * n + 1) + 1;
  }
}

int main() {
  int n, cnt;
  printf("Enter a number: ");
  scanf("%d", &n);
  cnt = count(n);
  printf("\nTotal steps required to reach 1: %d\n", cnt);
  return 0;
}
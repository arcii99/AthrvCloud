//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int sum(int n);

int main() {
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  printf("Sum of %d natural numbers is %d.\n", num, sum(num));
  
  return 0;
}

int sum(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n + sum(n-1);
  }
}
//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>

int main() {
  // define input variables
  int a, b, c;

  // prompt user for input values
  printf("Enter value for a (0 or 1): ");
  scanf("%d", &a);
  printf("Enter value for b (0 or 1): ");
  scanf("%d", &b);

  // perform XOR operation
  c = a ^ b;

  // print output
  printf("a XOR b = %d\n", c);

  return 0;
}
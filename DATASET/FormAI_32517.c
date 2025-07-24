//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>

int main() {
  int num, sum = 0;

  printf("Please enter 5 numbers: \n");

  // Loop through input and sum up
  for (int i = 0; i < 5; i++) {
    scanf("%d", &num);
    sum += num;
  }

  printf("The sum of the numbers you entered is: %d\n", sum);

  // Determine if the sum is even or odd
  if (sum % 2 == 0) {
    printf("The sum is even. Yay!\n");
  } else {
    printf("The sum is odd. Hooray!\n");
  }

  return 0;
}
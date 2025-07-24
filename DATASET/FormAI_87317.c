//FormAI DATASET v1.0 Category: Funny ; Style: surprised
#include <stdio.h>

int main() {
  int num1, num2, sum;

  printf("Enter the first number:");
  scanf("%d", &num1);

  printf("Enter the second number:");
  scanf("%d", &num2);

  sum = num1 + num2;

  if(sum > 100) {
    printf("Wow, the sum is over 100! This is surprising!\n");
  } else {
    printf("The sum is %d. Not as surprising as I hoped.\n", sum);
  }

  return 0;
}
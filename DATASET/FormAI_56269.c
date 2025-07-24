//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>

int main() {
  int x, y;

  printf("Enter your first number: ");
  scanf("%d", &x);

  printf("Enter your second number: ");
  scanf("%d", &y);

  printf("Wow, you picked %d and %d!\n", x, y);
  printf("I can't wait to see what you do with them...\n");

  int sum = x + y;
  printf("The sum of your numbers is: %d\n", sum);

  int difference = x - y;
  printf("The difference between your numbers is: %d\n", difference);

  int product = x * y;
  printf("The product of your numbers is: %d\n", product);

  float quotient = (float)x / y;
  printf("The quotient of your numbers is: %.2f\n", quotient);

  printf("I must say, you have quite the knack for math!\n");

  return 0;
}
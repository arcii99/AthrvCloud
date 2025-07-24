//FormAI DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int num1, num2, num3;
  float answer;

  printf("Enter three integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  answer = (((num1 * num2) % num3) / (float)num2) + ((num3 - num1 * num2) / (float)num3) + (num1 % 2) * (num2 % 2) * (num3 % 2);

  printf("The answer is: %.2f\n", answer);

  return 0;
}
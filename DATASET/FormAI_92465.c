//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

int main() {
  int num1, num2, num3, sum;
  float avg;

  printf("Enter three integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  sum = num1 + num2 + num3;
  avg = (float)sum/3;

  printf("\nSum of the three numbers: %d", sum);
  printf("\nAverage of the three numbers: %f", avg);

  if(num1 > num2 && num1 > num3) {
    printf("\n%d is the largest number.", num1);
  }
  else if(num2 > num1 && num2 > num3) {
    printf("\n%d is the largest number.", num2);
  }
  else {
    printf("\n%d is the largest number.", num3);
  }

  if(num1 < num2 && num1 < num3) {
    printf("\n%d is the smallest number.", num1);
  }
  else if(num2 < num1 && num2 < num3) {
    printf("\n%d is the smallest number.", num2);
  }
  else {
    printf("\n%d is the smallest number.", num3);
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sigmoid(float x) {
  return 1 / (1 + exp(-x));
}

int main() {
  int a, b, c, d;
  printf("Enter four integers: ");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  float sum = (a+b+c+d)/4.0;

  printf("The average of the four integers is: %f\n", sum);

  float activation = sigmoid(sum);

  printf("The sigmoid activation of the average is: %f\n", activation);

  int result = round(activation);

  printf("The rounded binary output is: %d\n", result);

  printf("\nThe cosmic gorilla has spoken. The result is %d\n", result);

  return 0;
}
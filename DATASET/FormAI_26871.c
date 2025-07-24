//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>

int main() {

  int data[10] = {10, 22, 13, 45, 67, 98, 33, 76, 55, 21};
  int min = data[0];
  int max = data[0];
  float average = 0.0;

  for (int i = 1; i < 10; i++) {
    if (data[i] < min) {
      min = data[i];
    }
    if (data[i] > max) {
      max = data[i];
    }
    average += data[i];
  }

  average /= 10;

  printf("The minimum value in the dataset is: %d\n", min);
  printf("The maximum value in the dataset is: %d\n", max);
  printf("The average value of the dataset is: %.2f\n", average);

  return 0;
}
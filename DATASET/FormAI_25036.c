//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>

int main() {
  int num[10] = {5, 6, 1, 8, 3, 9, 4, 2, 7, 10};
  int min = num[0], max = num[0], sum = 0, average = 0;

  for (int i = 0; i < 10; i++) {
    if (num[i] < min) {
      min = num[i];
    }
    if (num[i] > max) {
      max = num[i];
    }
    sum += num[i];
  }

  average = sum / 10;

  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);
  printf("Sum: %d\n", sum);
  printf("Average: %d\n", average);
  
  return 0;
}
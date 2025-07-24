//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dataset[10] = {2, 6, 8, 12, 16, 20, 24, 30, 34, 38};
  int min = dataset[0];
  int max = dataset[0];
  int sum = 0;
  float avg;

  for(int i = 0; i < 10; i++) {
    if(dataset[i] < min) {
      min = dataset[i];
    }
    if(dataset[i] > max) {
      max = dataset[i];
    }
    sum += dataset[i];
  }

  avg = (float) sum / 10;

  printf("Data Mining Results:\n");
  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);
  printf("Sum of values: %d\n", sum);
  printf("Average value: %f\n", avg);

  return 0;
}
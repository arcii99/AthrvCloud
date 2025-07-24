//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int main(void) {
  int numbers[ARRAY_SIZE];
  int i, sum = 0;
  float average;
  srand(time(NULL)); //seed for random number generation

  for (i = 0; i < ARRAY_SIZE; i++) {
    numbers[i] = rand() % (100 + 1 - 0) + 0; //generate random numbers between 0 and 100
    sum += numbers[i];
  }

  average = (float)sum / ARRAY_SIZE;

  printf("Randomly generated %d numbers between 0 and 100:\n", ARRAY_SIZE);
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", numbers[i]);
  }

  printf("\n\nAverage of the numbers: %.2f\n", average);

  int min = numbers[0], max = numbers[0], count1 = 0, count2 = 0;
  for (i = 0; i < ARRAY_SIZE; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    } else if (numbers[i] > max) {
      max = numbers[i];
    }

    if (numbers[i] < average) {
      count1++;
    } else if (numbers[i] > average) {
      count2++;
    }
  }

  printf("\nMinimum number in the list: %d", min);
  printf("\nMaximum number in the list: %d", max);
  printf("\nNumber of values below the average: %d", count1);
  printf("\nNumber of values above the average: %d\n", count2);

  return 0;
}
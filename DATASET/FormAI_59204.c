//FormAI DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the exciting world of C Data Mining!\n");

  // Let's start by creating a small dataset for our program.
  int size = 6;
  int data[] = {3, 10, 5, 2, 8, 7};

  printf("\nOur dataset contains the following elements:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }

  // Now, let's find the minimum element in our dataset.
  int min_val = data[0];
  for (int i = 1; i < size; i++) {
    if (data[i] < min_val) {
      min_val = data[i];
    }
  }

  printf("\n\nThe minimum element in our dataset is: %d\n", min_val);

  // Next, let's calculate the average of all the elements in our dataset.
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }

  float avg = (float) sum / size;
  printf("\nThe average of all the elements in our dataset is: %f\n", avg);

  // Finally, let's sort our dataset in ascending order using the bubble sort algorithm.
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j] > data[j+1]) {
        int temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }

  printf("\nAfter sorting, our dataset now looks like this:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }

  printf("\n\nThanks for exploring this exciting C Data Mining program with us!\n");

  return 0;
}
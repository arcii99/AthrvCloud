//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(float array[], int size) {
  // Empties the buckets and sets them to 0
  int i, j;
  float bucket[size];
  for (i = 0; i < size; ++i)
    bucket[i] = 0;

  // Fills the buckets with values from the array
  for (i = 0; i < size; ++i)
    ++bucket[(int)array[i]];

  // Sorts the values in the buckets
  for (i = 0, j = 0; j < size; ++j)
    for (int k = bucket[j]; k > 0; --k)
      array[i++] = j;

  printf("You just got sorted by the Bucket Sort algorithm! Haha!\n");
}

int main() {
  float array[10];
  int i;

  // Randomly assigns values to the array
  srand(time(NULL));
  for (i = 0; i < 10; ++i)
    array[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

  printf("Your unsorted list: \n\n");
  for (i = 0; i < 10; ++i)
    printf("%f\n", array[i]);

  bucket_sort(array, 10);

  printf("\n\nYour fully sorted list: \n\n");
  for (i = 0; i < 10; ++i)
    printf("%f\n", array[i]);

  return 0;
}
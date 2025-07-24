//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 1
#define MAX 1000

int main() {
  int i, j, temp;
  int array[MAX];
  clock_t start_time, end_time;
  double time_taken, avg_time = 0;

  srand(time(0));

  for (i = 0; i < MAX; i++) {
    array[i] = (rand() % (MAX - MIN + 1)) + MIN;
  }

  printf("Array of %d elements generated randomly between %d and %d.\n", MAX, MIN, MAX);

  for (i = 1; i < MAX; i++) {
    temp = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = temp;
  }

  printf("Array sorted using insertion sort algorithm.\n");

  for (i = 0; i < MAX; i = i + 100) {
    start_time = clock();

    for (j = 0; j < 100; j++) {
      temp = array[i + j];
    }

    end_time = clock();

    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken to access 100 elements starting from index %d is %lf seconds.\n", i, time_taken);

    avg_time += time_taken;
  }

  avg_time /= (MAX / 100);

  printf("Average time taken to access 100 elements is %lf seconds.", avg_time);

  return 0;
}
//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <time.h>

#define MAX_NUMS 1000000

void quicksort(int [], int, int);

int main() {
  int numbers[MAX_NUMS], i;
  double time_spent;
  
  // Generate random numbers
  srand(time(NULL));
  for (i = 0; i < MAX_NUMS; i++) {
    numbers[i] = rand() % 100;
  }
  
  // Benchmark quicksort
  clock_t begin = clock();
  quicksort(numbers, 0, MAX_NUMS-1);
  clock_t end = clock();
  
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time spent sorting %d numbers: %f seconds\n", MAX_NUMS, time_spent);
  
  return 0;
}

void quicksort(int numbers[], int left, int right) {
  int i, j, pivot, temp;
  if (left < right) {
    pivot = left;
    i = left;
    j = right;
    while (i < j) {
      while (numbers[i] <= numbers[pivot] && i < right)
        i++;
      while (numbers[j] > numbers[pivot])
        j--;
      if (i < j) {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
    temp = numbers[pivot];
    numbers[pivot] = numbers[j];
    numbers[j] = temp;
    quicksort(numbers, left, j - 1);
    quicksort(numbers, j + 1, right);
  }
}
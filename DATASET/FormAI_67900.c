//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
// A Performance-Critical Component Example Program
// in the Style of Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

// Function to Swap Two Integers
void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to Sort an Array Using Quick Sort Algorithm
void quicksort(int* arr, int start, int end)
{
  if (start >= end)
    return;

  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j <= end - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[end]);

  quicksort(arr, start, i);
  quicksort(arr, i + 2, end);
}

int main()
{
  int arr[N];

  // Generating Random Numbers
  srand(time(0));

  printf("The Adventure of the Performance-Critical Component\n\n");

  // Filling the Array with Random Numbers
  for (int i = 0; i < N; i++)
    arr[i] = rand() % 1000000;

  printf("Initial Array: ");
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  printf("...\n\n");

  // Sorting the Array Using Quick Sort Algorithm
  printf("Processing...\n\n");
  clock_t start_time = clock();
  quicksort(arr, 0, N - 1);
  clock_t end_time = clock();

  printf("Sorted Array: ");
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  printf("...\n\n");

  // Printing the Execution Time
  printf("The performance-critical component has completed its task.\n");
  printf("The execution time is %f seconds.\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

  printf("\n\nThe end.\n");

  return 0;
}
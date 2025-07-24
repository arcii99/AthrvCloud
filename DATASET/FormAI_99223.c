//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 100000
#define ITERATIONS 10000

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

// Generate test data
void generateTestData(int *arr, int n)
{
  int i;

  // Seed random number generator
  srand(time(NULL));

  // Fill array with random numbers
  for(i = 0; i < n; i++)
    arr[i] = rand() % MAX_NUMS;
}

// Sort test data using Quicksort algorithm
void sortData(int *arr, int n)
{
  qsort(arr, n, sizeof(int), compare);
}

// Main program
int main()
{
  int i, j;
  int arr[MAX_NUMS];

  // Generate test data
  generateTestData(arr, MAX_NUMS);

  // Iterate over data multiple times
  for(i = 0; i < ITERATIONS; i++)
  {
    // Sort data
    sortData(arr, MAX_NUMS);

    // Print sorted data
    for(j = 0; j < MAX_NUMS; j++)
      printf("%d ", arr[j]);

    printf("\n");
  }

  return 0;
}
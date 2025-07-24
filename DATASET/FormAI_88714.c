//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <time.h>

// Brave C Benchmarking Example Program

void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n-1; i++)
  {
    for (j = 0; j < n-i-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main()
{
  int arr[100000];
  int n = 100000;
  clock_t start, end;
  double cpu_time_used;

  // Generate random array elements
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100000;

  // Calculate time taken for bubble sort
  start = clock();
  bubbleSort(arr, n);
  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("Time taken for bubble sort: %f seconds", cpu_time_used);

  return 0;
}
//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void bubble_sort(int* arr, int size) {  
  for (int i = 0; i < size - 1; i++) {       
    for (int j = 0; j < size - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        // Swap arr[j] and arr[j+1]
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }
}

void generate_random_array(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
}

double benchmark_bubble_sort() {
  int arr[ARRAY_SIZE];
  generate_random_array(arr, ARRAY_SIZE);

  // Record the start time
  clock_t start_time = clock();

  bubble_sort(arr, ARRAY_SIZE);

  // Record the end time
  clock_t end_time = clock();

  // Calculate the elapsed time in seconds
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  return elapsed_time;
}

int main() {
  double total_time = 0.0;

  printf("Starting Benchmarking...\n");

  // Call the bubble sort 10 times and record the total time
  for (int i = 0; i < 10; i++) {
    double elapsed_time = benchmark_bubble_sort();
    printf("Iteration %d: %f seconds\n", i+1, elapsed_time);
    total_time += elapsed_time;
  }

  // Calculate the average time
  double average_time = total_time / 10;

  printf("Average Time: %f seconds\n", average_time);

  return 0;
}
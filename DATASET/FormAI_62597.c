//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 10

// Function to print array
void print_array(int arr[]) {
  int i;
  for (i = 0; i < ARRAY_SIZE; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to swap two elements of array
void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to perform counting sort on the given array
void counting_sort(int arr[], int n, int exp) {
  int output[n], i, count[10] = {0};

  // Count the occurences of digit at given place
  for (i = 0; i < n; ++i)
    count[(arr[i] / exp) % 10]++;

  // Update the count array 
  for (i = 1; i < 10; ++i)
    count[i] += count[i - 1];

  // Build the output array
  for (i = n - 1; i >= 0; --i) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    --count[(arr[i] / exp) % 10];
  }

  // Copy the output array to original array
  for (i = 0; i < n; ++i)
    arr[i] = output[i];
}

// Bucket Sort function
void bucket_sort(int arr[]) {
  int i, j, max_val, exp;

  // Reduce the values of all elements by dividing with largest element
  max_val = arr[0];
  for (i = 1; i < ARRAY_SIZE; ++i) {
    if (arr[i] > max_val)
      max_val = arr[i];
  }

  // Divide each element by largest element and multiply by (n-1) to get index of bucket
  for (i = 0; i < ARRAY_SIZE; ++i) {
    arr[i] = ((arr[i] * (ARRAY_SIZE - 1)) / max_val);
  }

  // Apply counting sort on each bucket
  for (exp = 1; (max_val / exp) > 0; exp *= 10) {
    counting_sort(arr, ARRAY_SIZE, exp);
  }

  // Multiply each element by largest element and divide by (n-1) to revert back to original value
  for (i = 0; i < ARRAY_SIZE; ++i) {
    arr[i] = ((arr[i] * max_val) / (ARRAY_SIZE - 1));
  }
}

int main() {
  int arr[ARRAY_SIZE] = {98, 23, 54, 23, 67, 12, 2, 8, 12, 10};
  printf("Before sorting: ");
  print_array(arr);

  bucket_sort(arr);
  printf("After sorting: ");
  print_array(arr);
  
  return 0;
}
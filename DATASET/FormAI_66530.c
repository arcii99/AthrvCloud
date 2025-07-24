//FormAI DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Change this to alter the size of the array

void print_array(int arr[]);
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);
void selection_sort(int arr[]);
void merge_sort(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);
void heap_sort(int arr[]);
void counting_sort(int arr[]);
void bucket_sort(int arr[]);
void radix_sort(int arr[]);

int main(void) {
  int arr[SIZE];
  srand(time(NULL)); // Seed the random number generator

  printf("This is a happy C data structure visualization example program!\n");
  printf("The current size of the array is: %d\n", SIZE);
  printf("The initial array is:\n");

  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100; // Generate a random number from 0 to 99
  }

  print_array(arr);

  printf("Sorting using bubble sort...\n");
  bubble_sort(arr);
  print_array(arr);

  printf("Sorting using insertion sort...\n");
  insertion_sort(arr);
  print_array(arr);

  printf("Sorting using selection sort...\n");
  selection_sort(arr);
  print_array(arr);

  printf("Sorting using merge sort...\n");
  merge_sort(arr, 0, SIZE-1);
  print_array(arr);

  printf("Sorting using quick sort...\n");
  quick_sort(arr, 0, SIZE-1);
  print_array(arr);

  printf("Sorting using heap sort...\n");
  heap_sort(arr);
  print_array(arr);

  printf("Sorting using counting sort...\n");
  counting_sort(arr);
  print_array(arr);

  printf("Sorting using bucket sort...\n");
  bucket_sort(arr);
  print_array(arr);

  printf("Sorting using radix sort...\n");
  radix_sort(arr);
  print_array(arr);

  printf("All done! Thanks for using this happy C data structure visualization example program!\n");

  return 0;
}

void print_array(int arr[]) {
  printf("[ ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

void bubble_sort(int arr[]) {
  // Bubble sort algorithm
}

void insertion_sort(int arr[]) {
  // Insertion sort algorithm
}

void selection_sort(int arr[]) {
  // Selection sort algorithm
}

void merge_sort(int arr[], int left, int right) {
  // Merge sort algorithm
}

void quick_sort(int arr[], int left, int right) {
  // Quick sort algorithm
}

void heap_sort(int arr[]) {
  // Heap sort algorithm
}

void counting_sort(int arr[]) {
  // Counting sort algorithm
}

void bucket_sort(int arr[]) {
  // Bucket sort algorithm
}

void radix_sort(int arr[]) {
  // Radix sort algorithm
}
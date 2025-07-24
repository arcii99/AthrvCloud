//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void initialize_array(int* arr){
  srand(time(NULL));
  for(int i = 0; i < SIZE; i++){
    arr[i] = rand() % 100;
  }
}

void print_array(int* arr){
  for(int i = 0; i < SIZE; i++){
    printf("%d ", arr[i]);
  }
}

void insertion_sort(int* arr){
  int key, j;
  for(int i = 1; i < SIZE; i++){
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void run_insertion_sort(int* arr){
  clock_t start = clock();
  insertion_sort(arr);
  clock_t end = clock();
  printf("\n\nInsertion sort took %lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main(){
  int arr[SIZE];
  initialize_array(arr);
  printf("Original Array:\n");
  print_array(arr);
  run_insertion_sort(arr);
  printf("Sorted Array:\n");
  print_array(arr);
  return 0;
}
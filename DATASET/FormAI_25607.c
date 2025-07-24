//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARR_SIZE 100000

int main(){

  clock_t start, end;
  double cpu_time_used, sum = 0;
  
  // Generating a random array of ARR_SIZE elements
  int arr[ARR_SIZE];
  for(int i=0; i<ARR_SIZE; i++){
    arr[i] = rand()%100; // Generating random numbers between 0-99
  }

  // Benchmarking Bubble sort algorithm
  printf("Bubble sort benchmarking...\n");
  start = clock();

  for(int i=0; i<ARR_SIZE-1; i++){
    for(int j=0; j<ARR_SIZE-i-1; j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;        
      }
    }
  }

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Bubble sort completed in %f seconds.\n", cpu_time_used); 

  // Benchmarking Selection sort algorithm
  printf("Selection sort benchmarking...\n");
  for(int i=0; i<ARR_SIZE; i++){
    arr[i] = rand()%100; // Re-generating random array for fair comparison
  }
  start = clock();

  for(int i=0; i<ARR_SIZE-1; i++){
    int min_idx = i;
    for(int j=i+1; j<ARR_SIZE; j++){
      if(arr[j]<arr[min_idx]){
        min_idx = j;        
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Selection sort completed in %f seconds.\n", cpu_time_used); 

  // Benchmarking Insertion sort algorithm
  printf("Insertion sort benchmarking...\n");
  for(int i=0; i<ARR_SIZE; i++){
    arr[i] = rand()%100; // Re-generating random array for fair comparison
  }
  start = clock();

  for(int i=1; i<ARR_SIZE; i++){
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Insertion sort completed in %f seconds.\n", cpu_time_used); 

  // Benchmarking Quick sort algorithm
  printf("Quick sort benchmarking...\n");
  for(int i=0; i<ARR_SIZE; i++){
    arr[i] = rand()%100; // Re-generating random array for fair comparison
  }
  start = clock();

  quickSort(arr, 0, ARR_SIZE-1); // Calling Quick sort function

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Quick sort completed in %f seconds.\n", cpu_time_used); 

  return 0;
}

// Quicksort function
void quickSort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

// Partitioning function for Quicksort
int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = low-1;
  for(int j=low; j<high; j++){
    if(arr[j]<pivot){
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;
  return i+1;
}
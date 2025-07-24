//FormAI DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function for Quick Sort algorithm
void quickSort(int arr[], int left, int right){
  
  int i = left, j = right;
  
  int pivot = arr[(left + right)/2];
  
  while(i <= j){
    
    while(arr[i] < pivot)
      i++;
    
    while(arr[j] > pivot)
      j--;
    
    if(i <= j){
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  }
  
  if(left < j)
    quickSort(arr, left, j);
  
  if(i < right)
    quickSort(arr, i, right);
}

// Function to print the array
void printArray(int arr[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Driver function
int main(){
  
  int arr[] = {5, 2, 8, 12, 45, 3, 1};
  
  int size = sizeof(arr)/sizeof(arr[0]);
  
  printf("Original Array: ");
  printArray(arr, size);
  
  quickSort(arr, 0, size-1);
  
  printf("Sorted Array: ");
  printArray(arr, size);
  
  return 0;
}
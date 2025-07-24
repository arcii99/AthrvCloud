//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include<stdio.h>

// This program sorts an array of integers in descending order
// using the selection sort algorithm

void selection_sort(int arr[], int size){
  int i, j, max, temp;

  for(i=0; i<size-1; i++){
    max = i;
    for(j=i+1; j<size; j++){
      if(arr[j] > arr[max]){
        max = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
}

int main(){
  int arr[] = {23, 56, 12, 89, 7, 46, 92, 37, 61, 15};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Original array:\n");
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }

  selection_sort(arr, size);

  printf("\nSorted array in descending order:\n");
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}
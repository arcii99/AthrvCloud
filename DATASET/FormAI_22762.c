//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>

void selectionSort(int arr[], int n){
  int i, j, max_index, temp;
  for(i = 0; i < n-1; i++){
    max_index = i;
    for(j = i+1; j < n; j++){
      if(arr[j] > arr[max_index]){
        max_index = j;
      }
    }
    // Swapping the elements
    temp = arr[i];
    arr[i] = arr[max_index];
    arr[max_index] = temp;
  }
}

int main(){
  int arr[] = {12, 45, 1, 27, 63, 20};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i;
  printf("Before Sorting: ");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  selectionSort(arr, n);
  printf("After Sorting (Descending Order): ");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
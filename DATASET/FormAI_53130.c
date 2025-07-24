//FormAI DATASET v1.0 Category: Sorting ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, j, temp;
  printf("Enter the number of elements you wish to sort: ");
  scanf("%d", &n);
  int arr[n];
  
  for(i=0; i<n; i++){
      printf("Enter element %d: ", i+1);
      scanf("%d", &arr[i]);
  }

  printf("Original array:\n");
  for(i=0; i<n; i++){
      printf("%d ", arr[i]);
  }

  //bubble sort
  for(i=0; i<n-1; i++){
      for(j=0; j<n-i-1; j++){
          if(arr[j] > arr[j+1]){
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
          }
      }
  }
  
  printf("\nSorted array using bubble sort:\n");
  for(i=0; i<n; i++){
      printf("%d ", arr[i]);
  }

  return 0;
}
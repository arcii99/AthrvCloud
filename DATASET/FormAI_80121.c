//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int retro_search(int arr[], int n, int x){
  int i;
  for(i = n-1; i >= 0; i--){
    if(arr[i] == x)
      return i;
  }
  return -1;
}

void main(){
  int n, x, result;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int *arr = (int*)malloc(n*sizeof(int));
  printf("Enter array elements:\n");
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter element to search: ");
  scanf("%d", &x);
  result = retro_search(arr, n, x);
  if(result == -1){
    printf("Element not found\n");
  }
  else{
    printf("Element found at index %d\n", result);
  }
  free(arr);
}
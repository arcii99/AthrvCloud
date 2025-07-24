//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

int main() {
  int size, i, key;
  printf("Enter the size of the array:\n");
  scanf("%d", &size);
  
  int arr[size];
  
  printf("Enter the array of integers:\n");
  
  for(i=0; i<size; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("Enter the search element:\n");
  scanf("%d", &key);
  
  for(i=0; i<size; i++) {
    if(arr[i] == key) {
      printf("Element found at index %d.\n", i);
      break;
    }
  }
  
  if(i == size) {
    printf("Element not found.\n");
  }
  
  return 0;
}
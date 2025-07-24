//FormAI DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>

void sorting(int arr[], int size) {
  int i, j, temp;

  for(i = 0; i < size - 1; i++) {
    for(j = i + 1; j < size; j++) {
      if(arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void display(int arr[], int size) {
  int i;

  printf("Sorted Array\n");
  for(i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  int arr[] = {5, 1, 4, 2, 0, 6, 3};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array\n");
  display(arr, size);

  sorting(arr, size);

  display(arr, size);
  
  return 0;
}
//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>

int main() {
  int size, i, j, temp;
  
  printf("How many numbers would you like to sort? ");
  scanf("%d", &size);
  
  int arr[size];
  
  for (i = 0; i < size; i++) {
    printf("Enter number %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  
  printf("\nUnsorted List: ");
  
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  for (i = 0; i < size - 1; i++) {  
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  printf("\n\nSorted List: ");
  
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
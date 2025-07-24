//FormAI DATASET v1.0 Category: Digital signal processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr1[100], arr2[100], arr3[100];
  int i, n;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  printf("Enter elements of array 1:\n");
  for(i=0; i<n; i++) {
    scanf("%d", &arr1[i]);
  }

  printf("Enter elements of array 2:\n");
  for(i=0; i<n; i++) {
    scanf("%d", &arr2[i]);
  }

  printf("The elements of array 1 are:\n");
  for(i=0; i<n; i++) {
    printf("%d ", arr1[i]);
  }

  printf("\nThe elements of array 2 are:\n");
  for(i=0; i<n; i++) {
    printf("%d ", arr2[i]);
  }

  printf("\nThe elements of array 3 are:\n");
  for(i=0; i<n; i++) {
    arr3[i] = arr1[i] + arr2[i];
    printf("%d ", arr3[i]);
  }

  printf("\n");

  return 0;
}
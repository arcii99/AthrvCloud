//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main() {
  int* ptr;
  printf("Surprise! Welcome to the memory allocation game.\n");
  printf("Please enter the number of integers you want to store in array: ");
  int n;
  scanf("%d", &n);

  ptr = (int *) malloc(n * sizeof(int));
  if(ptr == NULL) {
    printf("Oops! Memory allocation failed\n");
    return 0;
  } else {
    printf("Wow! Memory allocation successful\n");
  }

  printf("Please enter %d integers to store in the array\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", ptr + i);
  }

  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += *(ptr + i);
  }
  printf("The sum of all integers in the array is %d\n", sum);

  free(ptr);
  printf("Memory freed successfully. Have a nice day!\n");
  return 0;
}
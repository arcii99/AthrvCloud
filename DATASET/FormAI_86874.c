//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Hello, fellow programmers! Are you ready for a sorting adventure? \n");

  int my_array[10] = {2, 4, 7, 1, 3, 8, 5, 10, 6, 9};
  int i, j, temp;
  
  printf("Let's take the following unsorted array:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", my_array[i]);
  }
  printf("\n");

  printf("Now, let's sort it with the famous Bubble Sort algorithm!\n");

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 9-i; j++) {
      if (my_array[j] > my_array[j+1]) {
        temp = my_array[j];
        my_array[j] = my_array[j+1];
        my_array[j+1] = temp;
      }
    }
  }

  printf("And... voilà! Here is our sorted array:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", my_array[i]);
  }
  printf("\n");

  printf("I hope you enjoyed this sorting adventure as much as I did!\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>

int main() {
  printf("Hello curious coder!\n");
  printf("Are you ready to see a unique C Sorting example program?\n");

  int array[] = {3, 2, 6, 4, 7, 8, 1, 5};
  int n = sizeof array / sizeof array[0];

  printf("Before sorting:\n");
  for(int i=0; i<n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Here's the curious part:
  printf("Let's sort the array using a technique called Dancing Bubble Sort!\n");
  printf("This sorting technique involves swapping adjacent values in the array in a dance-like fashion.\n");
  printf("Each swap involves moving the smaller value to the left of the larger value.\n");

  for(int i=0; i<n-1; i++) {
    printf("Dance #%d:\n", i+1);
    for(int j=0; j<n-i-1; j++) {
      if(array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        printf("Swapped %d with %d\n", array[j+1], array[j]);
      }
    }
    printf("\n");
  }

  printf("\nAfter sorting:\n");
  for(int i=0; i<n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Ta-da! The array has been sorted using Dancing Bubble Sort.\n");
  printf("I hope you found this example program both curious and amusing.\n");

  return 0;
}
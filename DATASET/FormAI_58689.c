//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>

int main() {

  printf("Let's play a game!\n");
  printf("I will give you an array of numbers, you have to make it sorted\n");
  printf("But there is a catch! You can only swap adjacent elements\n");

  int arr[] = {5, 6, 1, 2, 9, 8, 3, 4, 7, 0};
  int n = sizeof(arr)/sizeof(int);

  printf("Unsorted Array: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Sorting Array now...\n");

  int swaps = 0;
  for(int i=0; i<n-1; i++) {
    if(arr[i] > arr[i+1]) {
      int temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
      swaps++;
    }
  }

  printf("Sorted Array: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Number of Swaps: %d\n", swaps);

  printf("Congratulations, you sorted the array!\n");
  printf("Thanks for playing!\n");

  return 0;
}
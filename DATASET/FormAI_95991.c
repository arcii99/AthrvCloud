//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>

void main() {
  printf("Oh my goodness, I cannot believe what just happened!\n\n");

  int arr[] = {15, 90, 19, 25, 8, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The unsorted array is: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\nBut wait, I have a plan! I'm going to sort this array using bubble sort algorithm!\n");
  // bubble sort algorithm starts here
  int i, j, temp;
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-i-1; j++) {
      if(arr[j]>arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  // bubble sort algorithm ends here

  printf("\nAfter bubble sorting the array, it now looks like this: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\nWow, that was amazing! I can't believe I just sorted an array using C programming language! :D\n");
}
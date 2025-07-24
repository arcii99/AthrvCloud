//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow! I can't believe how fast this program is!\n");
  printf("I mean seriously, did you see how quickly those calculations completed?\n");
  printf("I bet this is one of the fastest programs you've ever seen!\n");
  printf("\n");

  int arr[100000];
  int i;

  for (i = 0; i < 100000; i++) {
    arr[i] = i;
  }

  int sum = 0;

  for (i = 0; i < 100000; i++) {
    sum += arr[i];
  }

  printf("The sum of the array is: %d\n", sum);
  printf("And did you see how quickly that loop completed?\n");
  printf("This program is truly performance-critical!\n");
  printf("\n");

  int j, k, temp;

  for (j = 0; j < 100000 - 1; j++) {
    for (k = 0; k < 100000 - 1 - j; k++) {
      if (arr[k] > arr[k + 1]) {
        temp = arr[k];
        arr[k] = arr[k + 1];
        arr[k + 1] = temp;
      }
    }
  }

  printf("The array has been sorted in ascending order!\n");
  printf("And look how quickly it happened!\n");
  printf("This program is a true performance champion!\n");
  
  return 0;
}
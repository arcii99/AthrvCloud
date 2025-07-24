//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>

int mind_bend_search(int arr[], int low, int high, int x) {
  if(low <= high) {
    int mid = low + (high - low) / 2;
    if(arr[mid] == x) {
      printf("You've found it!\n");
      return mid;
    }
    if(arr[mid] > x) {
      printf("Going right...\n");
      mind_bend_search(arr, mid + 1, high, x);
    }
    else {
      printf("Going left...\n");
      mind_bend_search(arr, low, mid - 1, x);
    }
  }
  else {
    printf("It's not in this array, sorry.\n");
    return -1;
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int x = 15;
  printf("You're looking for %d\n", x);
  mind_bend_search(arr, 0, 9, x);
  return 0;
}
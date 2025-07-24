//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

int main() {
  printf("Whoa, I am pleasantly surprised you're here to see my searching algorithm in action!\n");
  
  int arr[] = { 2, 3, 4, 10, 40 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  
  printf("Our array contains { 2, 3, 4, 10, 40 } and we are looking for the number 10.\n");
  
  int found = 0;
  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == x) {
      printf("Whoop, I found it at index %d!\n", i);
      found = 1;
      break;
    }
  }
  
  if (found == 0) {
    printf("Sorry, I couldn't find the number you were looking for.\n");
  }

  printf("Hope you enjoyed the show! Thank you for stopping by.\n");

  return 0;
}
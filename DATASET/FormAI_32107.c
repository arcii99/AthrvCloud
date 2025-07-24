//FormAI DATASET v1.0 Category: Searching algorithm ; Style: happy
// Happy Searching Algorithm Example Program
// By Chatbot

#include <stdio.h>

int main() {
  int arr[10] = {14, 3, 57, 23, 8, 10, 1, 9, 6, 37};
  int n = 10;
  int search = 57;
  int found = 0;
  int i;

  printf("Welcome to my happy searching algorithm!\n");
  printf("Let's search for the number %d...\n", search);

  for(i = 0; i < n; i++) {
    if(arr[i] == search) {
      printf("Hooray! I found %d at position %d.\n", search, i+1);
      found = 1;
    }
  }

  if(found == 0) {
    printf("Oops! %d is not in the array.\n", search);
  }

  printf("Thank you for using my happy searching algorithm! :)\n");

  return 0;
}
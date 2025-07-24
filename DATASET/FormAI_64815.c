//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my error handling program!\nLet's see what kinds of errors we can come up with today...\n\n");

  // Let's try to divide by zero
  int a = 5, b = 0;
  int c;
  printf("Let's divide %d by %d\n", a, b);
  if (b == 0) {
    printf("Uh oh, dividing by zero is not allowed!\n");
    printf("We need to handle this error somehow...\n");

    // We can't divide by zero, so let's just set the answer to zero
    printf("Okay, let's set the answer to zero and move on.\n");
    c = 0;
  } else {
    c = a / b;
  }
  printf("The answer is %d\n\n", c);

  // Now let's try to write to a read-only file
  printf("Let's try to write to a read-only file...\n");
  FILE *f = fopen("readonly.txt", "r");
  if (f == NULL) {
    printf("Oops, we couldn't open the file!\n");
    printf("This is an error we can't handle, so we need to exit the program.\n");
    return 1;
  }
  printf("Okay, we opened the file successfully.\n");

  // Now let's try to read beyond the end of an array
  printf("\nLet's try to read beyond the end of an array...\n");
  int arr[5] = {1, 2, 3, 4, 5};
  printf("We have an array of size 5.\n");
  printf("Let's try to access arr[10]: %d\n", arr[10]);
  printf("Oops, we accessed beyond the end of the array!\n");
  printf("We can't handle this error, so we need to exit the program.\n");

  return 0;
}
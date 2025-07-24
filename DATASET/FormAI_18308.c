//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

int puzzlingRecursive(int n, int x) {
  if (n == 0) {
    return x;
  }
  return puzzlingRecursive(n-1, x+n);
}

int main() {
  printf("Welcome to the Puzzling Recursive Program!\nEnter 'quit' at any time to exit.\n\n");
  while (1) {
    // get user input
    int n, x;
    printf("Enter two numbers n and x, separated by a space: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d %d", &n, &x) != 2) {
      if (strcmp(input, "quit\n") == 0) {
        printf("Goodbye!\n");
        return 0;
      }
      printf("Invalid input. Please try again.\n");
      continue;
    }
    // call puzzlingRecursive function
    int result = puzzlingRecursive(n, x);
    // print result
    printf("puzzlingRecursive(%d, %d) = %d\n", n, x, result);
  }
  return 0;
}
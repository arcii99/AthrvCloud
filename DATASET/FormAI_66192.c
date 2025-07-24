//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void recursive_function(int n) {
  if (n == 0) {
    return;
  } else {
    printf("%d\n", n);
    recursive_function(n-1);
  }
}

int main() {
  printf("This program will count down from a number provided by the user in a peaceful manner.\n");

  int n;
  printf("Please enter a positive integer: ");
  scanf("%d", &n);

  if (n < 1) {
    printf("Invalid input.\n");
  } else {
    printf("Starting countdown...\n");
    recursive_function(n);
    printf("Countdown complete. Peace out!\n");
  }

  return 0;
}
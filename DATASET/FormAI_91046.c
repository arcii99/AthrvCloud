//FormAI DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>

void recursiveFunction(int num) {
  if (num < 10) {
    printf("%d, ", num);
    recursiveFunction(num + 1);
  }
}

int main() {
  printf("Welcome to the recursive function!\n");
  printf("This function will print the first 10 positive integers.\n\n");

  printf("Here they are: ");

  recursiveFunction(1);

  printf("aren't they great?!");

  return 0;
}
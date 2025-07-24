//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

void printNums(int n) {
  if (n < 0) { // base case
    printf("Error: n cannot be negative.");
    return;
  } else if (n == 0) { // base case
    printf("0");
    return;
  } else if (n == 1) { // base case
    printf("1");
    return;
  } else {
    printNums(n-1); // recursive call
    printf("%d", n); // print current number
    return;
  }
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("Printed in reverse order: ");
  printNums(n);
  return 0;
}
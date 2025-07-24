//FormAI DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>

// Define a function that calls itself recursively
int recursive(int n) {
  if (n == 0) { // check for the base case
    return 0;
  } else { // recursive case
    return n + recursive(n-1);
  }
}

int main() {
  int num = 10; // specify the input value
  int result = recursive(num); // call the recursive function
  printf("The sum of numbers from 1 to %d is %d\n", num, result);
  return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: curious
/* Welcome to the Performance-Critical Component Challenge! */
/* This program will generate the Fibonacci sequence up to a specified number. */

#include <stdio.h>

int main() {
  int num; // user-specified number
  int i = 0, j = 1, k = 0; // variables for generating the sequence
  
  printf("Welcome! Please enter a positive integer: ");
  scanf("%d", &num); // get input from user
  
  printf("Generating Fibonacci sequence up to %d:\n", num);
  
  // loop to generate the sequence
  while (k <= num) {
    printf("%d ", k);
    i = j; // set i to previous value of j
    j = k; // set j to previous value of k
    k = i + j; // calculate new value of k
  }
  
  printf("\nDone!\n");
  
  return 0;
}
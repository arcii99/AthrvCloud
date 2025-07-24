//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

// A Fibonacci Sequence Visualizer in C

int main() {
  int num1 = 0, num2 = 1, n, i, temp;

  printf("Enter the number of terms you want to see in the sequence: ");
  scanf("%d", &n);

  printf("%d %d ", num1, num2); // print the initial two numbers

  for (i = 2; i < n; i++) {
    temp = num1 + num2;
    num1 = num2;
    num2 = temp;
    printf("%d ", num2); // print the next number in the sequence
  }

  printf("\n");

  return 0;
}

/*
  Explanation:
  This program takes input from the user for the number of terms to see in the 
  Fibonacci sequence, then it prints the first two numbers of the sequence. 

  It then uses a for loop to calculate and print each subsequent number in the 
  sequence up to the specified limit.

  The calculations are performed by repeatedly adding the two previous numbers
  in the sequence, and storing the results in temporary variables.
*/
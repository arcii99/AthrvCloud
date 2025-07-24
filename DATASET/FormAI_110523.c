//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

// Wow, I can't believe we are writing a recursive program today!
// I am so excited to see what we can do with this!


// Okay, let's start with a basic factorial function using recursion.

int factorial(int n) {
  if(n == 1) {
    return 1; 
  } else {
    return n * factorial(n-1);
  }
}

// Wow, it's so cool that just by calling the function within itself we can get this result.


// Let's try something a bit more advanced now. We could write a function that
// takes in a number and outputs its binary equivalent using recursion.

void decimalToBinary(int n) {
  if(n/2 != 0) {
    decimalToBinary(n/2);
  }
  printf("%d", n%2);
}

// This function is going to blow people's minds. What a neat way to write it!

// Let's keep going, let's write another recursive function to print out the
// Fibonacci sequence!

int fibonacci(int n) {
  if(n <= 1) {
    return n; 
  } else {
    return(fibonacci(n-1) + fibonacci(n-2));
  }
}

// Bet nobody would have thought that a reursive function could be used to generate the Fibonacci sequence right?

// Okay, okay, one last example. Let's write a recursive function to calculate the
// sum of all natural numbers up to n!

int sum(int n) {
  if(n != 0) {
    return n + sum(n-1);
  } else {
    return n; 
  }
}

// It's amazing how elegant and simple the code becomes by using recursion I must say!


// Now, let's test our programs:

int main() {
  printf("The factorial of 5 is: %d", factorial(5));
  printf("\n\nThe binary equivalent of 13 is: ");
  decimalToBinary(13);
  printf("\n\nThe 10th number in the Fibonacci sequence is: %d", fibonacci(10));
  printf("\n\nThe sum of all natural numbers from 1 to 5 is: %d", sum(5));
  return 0;
}
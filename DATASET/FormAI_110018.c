//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#define MAX_N 100000 // maximum input value

unsigned long long memo[MAX_N + 1] = { 0 }; // array for memoization

// Function to calculate factorial with memoization
unsigned long long factorial(unsigned int n) {
   if (n == 0) {
      return 1;
   }
   
   if (n == 1) {
      return 1;
   }
   
   if (memo[n] != 0) { // if value is already stored in array
      return memo[n];
   }
   
   memo[n] = n * factorial(n - 1); // memoize value and return
   return memo[n];
}

int main() {
   unsigned int n = MAX_N; // set input value
   
   printf("Calculating factorial of %d...\n", n);
   
   unsigned long long result = factorial(n); // calculate factorial and store result
   
   printf("Result: %llu\n", result);
   
   return 0; // exit program
}
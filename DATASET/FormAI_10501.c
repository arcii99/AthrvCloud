//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to find the sum of first n natural numbers
int findSum(int n) {
   int sum = 0;
   for(int i = 1; i <= n; i++) {
      sum += i;
   }
   return sum;
}

// Function to find the difference between sum of squares of first n numbers and square of the sum
int findDifference(int n) {
   int squareOfSum = 0, sumOfSquares = 0, difference = 0;
   for(int i = 1; i <= n; i++) {
      sumOfSquares += i * i;
      squareOfSum += i;
   }
   squareOfSum = squareOfSum * squareOfSum;
   difference = squareOfSum - sumOfSquares;
   return difference;
}

// Main function
int main() {
   int n = 0;
   printf("Enter a natural number n: ");
   scanf("%d", &n);
   if(n <= 0) {
      printf("Invalid input! Please enter a natural number.\n");
      return 0;
   }
   int sum = findSum(n);
   int difference = findDifference(n);
   printf("Sum of first %d natural numbers = %d\n", n, sum);
   printf("Difference between square of sum of first %d natural numbers and sum of squares = %d\n", n, difference);
   return 0;
}
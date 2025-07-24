//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>

int fibonacci(int num); // Function declaration to calculate Fibonacci sequence
void printFibonacci(int num); // Function declaration to print Fibonacci sequence

int main() {
   int num;

   printf("Enter the number of terms in the Fibonacci sequence: ");
   scanf("%d", &num);

   // Function call to print the Fibonacci sequence
   printFibonacci(num);

   return 0;
}

int fibonacci(int num) {
   // Base case
   if (num == 0 || num == 1) {
      return num;
   }
   else {
      // Recursive call to calculate Fibonacci sequence
      return fibonacci(num - 1) + fibonacci(num - 2);
   }
}

void printFibonacci(int num) {
   int i;

   printf("The Fibonacci sequence is: ");

   // Loop to print the Fibonacci sequence
   for (i = 0; i < num; i++) {
      printf("%d ", fibonacci(i));
   }
}
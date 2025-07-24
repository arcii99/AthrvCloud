//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>

// Function to calculate Fibonacci sequence
int fibonacci(int num) {
   if(num <= 1) {
      return num;
   }
   else {
      return (fibonacci(num-1) + fibonacci(num-2));
   }
}

int main() {
   int i, n;

   printf("Enter the number of terms you want to print in Fibonacci sequence:");
   scanf("%d", &n);

   // Print the sequence
   printf("The Fibonacci Sequence is:\n");
   for(i=0; i<n; i++) {
      printf("%d, ", fibonacci(i));
   }

   printf("\n");
   return 0;
}
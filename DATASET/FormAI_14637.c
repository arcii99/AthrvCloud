//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>

int main() {
   int terms, i, fibonacci_num[50];
   //Taking input for number of terms to be displayed
   printf("Enter number of terms (max 50) in the Fibonacci Sequence: ");
   scanf("%d", &terms);
   
   //Initial two terms of fibonacci sequence
   fibonacci_num[0] = 0; 
   fibonacci_num[1] = 1;
   
   //Calculating the fibonacci sequence and storing it in an array
   for (i = 2; i < terms; i++) {
      fibonacci_num[i] = fibonacci_num[i-1] + fibonacci_num[i-2];
   }
   
   //Displaying the fibonacci sequence visually in the form of stars
   printf("Fibonacci Sequence up to %d terms:\n", terms);
   for (i = 0; i < terms; i++) {
      int j;
      //loop to print the number of stars equivalent to the value of fibonacci term
      for (j = 0; j < fibonacci_num[i]; j++) {
         printf("*");
      }
      printf("\n");
   }
   return 0;
}
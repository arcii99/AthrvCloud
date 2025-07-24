//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
// Ada Lovelace Style C educational program
// Program to display the first 20 terms of the Fibonacci sequence

#include <stdio.h>

int main() {
   int n, prev = 0, curr = 1, next;

   printf("The first 20 terms of the Fibonacci sequence:\n");

   for (n = 1; n <= 20; n++) {
      printf("%d.\t %d\n", n, curr); // Print current term

      // Calculate the next term and store in next
      next = prev + curr; 
      
      // Update previous and current terms for next iteration
      prev = curr; 
      curr = next; 
   }
   
   return 0;
}
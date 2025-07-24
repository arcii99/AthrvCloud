//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>

int main () {
   int fib1 = 0, fib2 = 1, count = 0, num;

   printf("Enter the number of terms you want to see the Fibonacci Sequence: ");
   scanf("%d", &num);

   printf("Are you ready for some math magic? Here we go! \n");

   printf("The Fibonacci Sequence up to %d terms is: \n", num);

   printf("%d, %d, ", fib1, fib2);
   count = 2;

   while (count < num) {
      int fibonacci = fib1 + fib2;
      printf("%d, ", fibonacci);
      fib1 = fib2;
      fib2 = fibonacci;
      count++;
   }

   printf("and that's how it's done! \n");
   return 0;
}
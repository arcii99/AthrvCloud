//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>

void main() {
   int n, first = 0, second = 1, next, c;
   printf("Enter the number of terms\n");
   scanf("%d",&n);
   printf("First %d terms of Fibonacci series are:\n", n);
   
   for ( c = 0 ; c < n ; c++ ) {
      if ( c <= 1 )
         next = c;
      else {
         next = first + second;
         first = second;
         second = next;
      }
      printf("%d ", next);
      if (c == 0) {
        printf("\n* * * * * * * * * * * * * * * * * * * * *\n");
      } else if (c == 1) {
        printf("\n          * * * * * * * * * * * * *          \n");
      } else if (c % 2 == 0) {
        printf("\n    * * * * * * *     * * * * * * *    \n");
      } else {
        printf("\n* * * *   * * * * * * * * * * *   * * * *\n");
      }
   }
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>

int main() {
   int num, i, a = 0, b=1, c;
   printf("Enter the number of terms: ");
   scanf("%d", &num);
   printf("Fibonacci Series: ");

   for (i = 1; i <= num; i++) {
      printf("%d, ", a);
      c= a+b;
      a = b;
      b = c;
   }

   printf("\n\nThe Fibonacci Sequence has been visualized before you!");
   return 0;
}
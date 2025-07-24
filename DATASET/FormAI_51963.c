//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

int recursiveFunction(int n) {
   int result;

   if (n == 0) { // Base case
      result = 0;
   } else if (n == 1) { // Base case
      result = 1;
   } else {
      result = recursiveFunction(n - 1) + recursiveFunction(n - 2); // Recursive call
   }

   return result;
}

int main() {
   int n, i;

   printf("Enter the number of terms: ");
   scanf("%d", &n);

   printf("Fibonacci series: ");

   for (i = 0; i < n; i++) {
      printf("%d ", recursiveFunction(i));
   }

   return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

int recursiveSum(int n) {
   if (n == 0) // base case
      return 0;
   else
      return n + recursiveSum(n - 1); // recursive call
}

int main() {
   int num;
   printf("Enter a positive integer: ");
   scanf("%d", &num);
   printf("The sum of the first %d numbers is %d.", num, recursiveSum(num));
   return 0;
}
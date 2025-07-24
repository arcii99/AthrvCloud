//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

int recursive_sum(int n) {
   if(n == 0) {
      return n;
   } else {
      return n + recursive_sum(n-1);
   }
}

int main() {
   int number;
   printf("Enter a positive integer: ");
   scanf("%d", &number);

   int result = recursive_sum(number);

   printf("The sum of first %d natural numbers is: %d", number, result);
   return 0;
}
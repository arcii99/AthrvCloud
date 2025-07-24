//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

int main() {
   int n;
   printf("Enter a number: ");
   scanf("%d", &n);
   if (n < 0) { //checking if the number is negative
      printf("Error: Number should be positive");
   } else {
      int factorial = 1, i;
      for(i=1; i<=n; i++) {
         factorial *= i; //calculating the factorial
      }
      printf("%d! = %d", n, factorial);
   }
   return 0;
}
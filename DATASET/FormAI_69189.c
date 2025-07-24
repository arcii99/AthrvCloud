//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>

int main() {
   int n, factorial = 1;
   printf("Welcome to the Factorial Calculator!\n");
   printf("Enter a number you want to calculate the factorial of: ");
   scanf("%d", &n);
   
   if(n < 0) {
      printf("Error: Factorial of negative number does not exist!\n");
      return 0; // end program
   }

   for(int i = 1; i <= n; ++i){
      factorial *= i;
   }

   printf("The factorial of %d is %d\n", n, factorial);
   printf("Thank you for using this program!\n");

   return 0;
}
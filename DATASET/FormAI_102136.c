//FormAI DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>

// Function Prototypes
int factorial(int num);

int main() {
   int input;
   printf("Enter a number: ");
   scanf("%d", &input);
   
   printf("The factorial of %d is: %d", input, factorial(input));

   return 0;
}

// Recursive function for calculating factorial
int factorial(int num) {
   if (num == 0) {
      return 1;
   } else {
      return (num * factorial(num - 1));
   }
}
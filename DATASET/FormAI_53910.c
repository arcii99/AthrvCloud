//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>

int main() {
   int a, b, result;
   
   printf("Welcome to the Futuristic Arithmetic Calculator!\n");
   printf("Please enter two numbers you wish to add, subtract, multiply, or divide: \n");
   
   scanf("%d %d", &a, &b);
   
   // Addition Function
   result = a + b;
   printf("The sum of %d and %d is: %d\n", a, b, result);
   
   // Subtraction Function
   result = a - b;
   printf("The difference between %d and %d is: %d\n", a, b, result);
   
   // Multiplication Function
   result = a * b;
   printf("The product of %d and %d is: %d\n", a, b, result);
   
   // Division Function
   if (b == 0) {
     printf("Error: Cannot divide by zero.\n");
   }
   else {
     float division_result = (float)a / (float)b;
     printf("The quotient of %d and %d is: %.2f\n", a, b, division_result);
   }
   
   printf("Thank you for using the Futuristic Arithmetic Calculator. Have a nice day!\n");
   
   return 0;
}
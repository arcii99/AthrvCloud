//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {
   int num1, num2, choice, result;
   printf("Welcome to the immersive Arithmetic Program!\n");
   printf("Please enter two numbers: ");
   scanf("%d%d", &num1, &num2);
   printf("\nGreat! Now choose an arithmetic operation:\n");
   printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         result = num1 + num2;
         printf("The sum of %d and %d is %d.", num1, num2, result);
         break;

      case 2:
         result = num1 - num2;
         printf("The difference between %d and %d is %d.", num1, num2, result);
         break;

      case 3:
         result = num1 * num2;
         printf("The product of %d and %d is %d.", num1, num2, result);
         break;

      case 4:
         result = num1 / num2;
         printf("The quotient of %d divided by %d is %d with a remainder of %d.", num1, num2, result, (num1%num2));
         break;

      default:
         printf("Invalid choice! Please run the program again and enter a valid choice.");
         break;
   }
   return 0;
}
//FormAI DATASET v1.0 Category: Calculator ; Style: introspective
#include <stdio.h>

int main() {
   int first, second, result=0, choice;
  
   printf("This is a simple calculator program written in C.\n");

   printf("Please enter first number: ");
   scanf("%d", &first);

   printf("Please enter second number: ");
   scanf("%d", &second);

   printf("\nPlease choose an operation from the following: \n");
   printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         result = first + second;
         break;

      case 2:
         result = first - second;
         break;

      case 3:
         result = first * second;
         break;

      case 4:
         if(second == 0) {
            printf("Error! Division by zero is not allowed.");
            return 0;
         }

         result = first / second;
         break;

      default:
         printf("Invalid choice!");
   }

   printf("\nResult: %d\n", result);

   return 0;
}
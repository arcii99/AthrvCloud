//FormAI DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int num1, num2, choice;
   float result;

   printf("1. Find Square Root\n");
   printf("2. Find sin\n");
   printf("3. Find cos\n");
   printf("4. Find tan\n");
   printf("5. Find log\n");
   printf("6. Find power\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
   
   switch(choice) {
      case 1:
         printf("Enter a number to find square root: ");
         scanf("%d", &num1);
         result = sqrt(num1);
         printf("Square root of %d = %f", num1, result);
         break;
      case 2:
         printf("Enter a number to find sin: ");
         scanf("%d", &num1);
         result = sin(num1);
         printf("sin(%d) = %f", num1, result);
         break;
      case 3:
         printf("Enter a number to find cos: ");
         scanf("%d", &num1);
         result = cos(num1);
         printf("cos(%d) = %f", num1, result);
         break;
      case 4:
         printf("Enter a number to find tan: ");
         scanf("%d", &num1);
         result = tan(num1);
         printf("tan(%d) = %f", num1, result);
         break;
      case 5:
         printf("Enter a number to find log: ");
         scanf("%d", &num1);
         result = log(num1);
         printf("log(%d) = %f", num1, result);
         break;
      case 6:
         printf("Enter base number: ");
         scanf("%d", &num1);
         printf("Enter power number: ");
         scanf("%d", &num2);
         result = pow(num1, num2);
         printf("%d to the power of %d = %f", num1, num2, result);
         break;
      default:
         printf("Invalid choice");
   }

   return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to my random arithmetic program!\n");

   int a, b, c, operand, result;

   // get input from user
   printf("Enter first number: ");
   scanf("%d", &a);
   printf("Enter second number: ");
   scanf("%d", &b);

   // random operand
   srand(time(0));
   operand = rand() % 4;

   // arithmetic operation based on operand
   switch(operand) {
      case 0:
         c = a + b;
         printf("%d + %d = %d\n", a, b, c);
         break;
      case 1:
         c = a - b;
         printf("%d - %d = %d\n", a, b, c);
         break;
      case 2:
         c = a * b;
         printf("%d * %d = %d\n", a, b, c);
         break;
      case 3:
         if (b != 0) {
            result = a / b;
            c = a % b;
            printf("%d / %d = %d with remainder %d\n", a, b, result, c);
         } else {
            printf("Second number can't be 0 for division\n");
         }
         break;
      default:
         printf("Invalid operand\n");
   }

   printf("Thanks for using my program!");
   return 0;
}
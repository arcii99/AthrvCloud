//FormAI DATASET v1.0 Category: Arithmetic ; Style: content
#include <stdio.h>

int main() {
   int num1, num2, addition, subtraction, multiplication;
   float division;
   
   printf("Enter the first integer number: ");
   scanf("%d", &num1);
   
   printf("Enter the second integer number: ");
   scanf("%d", &num2);
   
   addition = num1 + num2;
   subtraction = num1 - num2;
   multiplication = num1 * num2;
   division = (float)num1 / num2;
   
   printf("\n-----------------\n");
   printf("Arithmetic Operations:\n");
   printf("-----------------\n");
   printf("%d + %d = %d\n", num1, num2, addition);
   printf("%d - %d = %d\n", num1, num2, subtraction);
   printf("%d * %d = %d\n", num1, num2, multiplication);
   printf("%d / %d = %.2f\n", num1, num2, division);
   
   return 0;
}
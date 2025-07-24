//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>

int main()
{
   int num1 = 10;
   int num2 = 20;
   int sum, diff, prod, quotient, remainder;
   
   // Addition 
   sum = num1 + num2;
   printf("The sum of %d and %d is %d.\n", num1, num2, sum);

   // Subtraction
   diff = num1 - num2;
   printf("The difference between %d and %d is %d.\n", num1, num2, diff);

   // Multiplication
   prod = num1 * num2;
   printf("The product of %d and %d is %d.\n", num1, num2, prod);

   // Division
   quotient = num1 / num2;
   remainder = num1 % num2;
   printf("%d divided by %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);

   // Logic Operators
   int a = 10;
   int b = 20;
   int c = 10;
   int d = 30;

   printf("a && b = %d\n", a && b );
   printf("a || b = %d\n", a || b );
   printf("!(a && b) = %d\n", !(a && b) );
   printf("a > b = %d\n", a > b );
   printf("b < d = %d\n", b < d );
   printf("a == c = %d\n", a == c );
   printf("b != d = %d\n", b != d );

   // Loops
   int i;
   for(i=0;i<5;i++){
       printf("This is iteration number %d.\n", i+1);
   }
   
   i = 0;
   while(i<5){
       printf("This is iteration number %d.\n", i+1);
       i++;
   }

   // Strings
   char string1[20] = "Hello, ";
   char string2[10] = "world!";
   strcat(string1, string2);
   printf("%s", string1);

   // Pointers
   int x = 10;
   int *pointer;
   pointer = &x;
   printf("The value of x is %d.\n", x);
   printf("The pointer points to the value %d.\n", *pointer);

   return 0;
}
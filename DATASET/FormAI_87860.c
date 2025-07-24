//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

int main() {
   int a = 12;
   float b = 3.14159;
   double c = 2.71828;
   char d = 'A';

   printf("The value of integer a is %d\n", a);
   printf("The value of float b is %.2f\n", b);
   printf("The value of double c is %.4f\n", c);
   printf("The value of character d is %c\n\n", d);

   int sum = a + b + c + d;
   printf("The sum of all four variables is %d\n", sum);

   int product = a * b * c * d;
   printf("The product of all four variables is %d\n", product);

   int quotient = a / b;
   printf("The quotient of integer a divided by float b is %d\n", quotient);

   float f_quotient = (float) a / b;
   printf("The quotient of integer a divided by float b is %.2f\n", f_quotient);

   int remainder = a % 5;
   printf("The remainder of integer a divided by 5 is %d\n", remainder);

   float power = pow(b, a);
   printf("The value of float b raised to the power of integer a is %.4f\n", power);

   int absolute = abs(-a);
   printf("The absolute value of -a is %d\n", absolute);

   return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

int main() {
   int num1 = 10, num2 = 5; // initializing two integers
   printf("The initial values are num1 = %d and num2 = %d\n", num1, num2);

   // storing the sum of num1 and num2 in num1
   num1 = num1 + num2;
   printf("The value of num1 after adding num2 is %d\n", num1);

   // subtracting num2 from num1 and storing the result in num2
   num2 = num1 - num2;
   printf("The value of num2 after subtracting num2 from num1 is %d\n", num2);

   // multiplying num1 and num2 and storing the result in num1
   num1 = num1 * num2;
   printf("The value of num1 after multiplying num1 and num2 is %d\n", num1);

   // dividing num1 by num2 and storing the result in num2
   num2 = num1 / num2;
   printf("The value of num2 after dividing num1 by num2 is %d\n", num2);

   // getting the remainder of num1 divided by num2 and storing the result in num1
   num1 = num1 % num2;
   printf("The value of num1 after getting the remainder of num1 divided by num2 is %d\n", num1);

   return 0;
}
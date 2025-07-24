//FormAI DATASET v1.0 Category: Funny ; Style: thoughtful
#include <stdio.h>

int main() {
   int num1 = 5;
   int num2 = 7;
   int num3 = 3;
   int result;

   result = num1 + num2 * num3; // multiplication has higher precedence

   printf("The result of num1 + num2 * num3 is %d\n", result);

   result = (num1 + num2) * num3; // parentheses override precedence

   printf("The result of (num1 + num2) * num3 is %d\n", result);

   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[20];

   sprintf(str3, "%s %s", str1, str2); // concatenate strings

   printf("The result of concatenating str1 and str2 is \"%s\"\n", str3);

   int num4 = 7;
   int num5 = 2;

   result = num4 / num5; // integer division truncates remainder

   printf("The result of num4 / num5 is %d\n", result);

   float num6 = 7.0;
   float num7 = 2.0;

   float result2 = num6 / num7; // floating-point division does not truncate remainder

   printf("The result of num6 / num7 is %.2f\n", result2); // use "%.2f" to format to 2 decimal places

   return 0;
}
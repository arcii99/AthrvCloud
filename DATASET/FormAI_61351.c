//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

int andOperation(int num1, int num2) {
   if(num1 == 0 || num2 == 0) {
      return 0;
   }
   else if(num1 == 1 && num2 == 1) {
      return 1;
   }
   else {
      return andOperation(num1 & num2, ~(~num1 | ~num2));
   }
}

int orOperation(int num1, int num2) {
   if(num1 == 1 || num2 == 1) {
      return 1;
   }
   else if(num1 == 0 && num2 == 0) {
      return 0;
   }
   else {
      return orOperation(num1 | num2, ~(~num1 & ~num2));
   }
}

int xorOperation(int num1, int num2) {
   if(num1 == num2) {
      return 0;
   }
   else {
      return xorOperation(num1 ^ num2, (num1 & num2) << 1);
   }
}

int main() {
   int num1, num2;
   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);

   printf("AND Operation of %d and %d is: %d\n", num1, num2, andOperation(num1, num2));
   printf("OR Operation of %d and %d is: %d\n", num1, num2, orOperation(num1, num2));
   printf("XOR Operation of %d and %d is: %d\n", num1, num2, xorOperation(num1, num2));

   return 0;
}
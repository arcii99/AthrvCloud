//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>

int main() {

   int num, remainder, binary = 0, base = 1;

   printf("Enter a decimal integer: ");
   scanf("%d", &num);
    
   printf("Converting decimal to binary...\n");

   while (num > 0) {
       remainder = num % 2;
       binary = binary + remainder * base;
       num = num / 2;
       base = base * 10;
   }

   printf("The binary equivalent of the decimal integer is: %d\n", binary);

   return 0;
}
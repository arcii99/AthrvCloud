//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
   int num, digit, sum = 0, pos = 1;

   printf("Enter a number: ");
   scanf("%d", &num);

   while (num > 0) {
      digit = num % 10;
      num /= 10;

      if (pos % 2 == 0) {
         digit *= 2;

         if (digit > 9) {
            digit = digit % 10 + digit / 10;
         }
      }

      sum += digit;
      pos++;
   }

   int checksum = 10 - (sum % 10);
   printf("Checksum = %d\n", checksum);

   return 0;
}
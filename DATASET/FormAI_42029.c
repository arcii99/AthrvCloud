//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int num) {
   int rem = 0;
   if(num == 0) {
      return;
   }
   else {
      rem = num % 16;
      if(rem < 10) {
         printf("%d", rem);
      }
      else {
         printf("%c", rem - 10 + 'a');
      }
      convertToHex(num / 16);
   }
}

int main() {
   int dec, temp;
   printf("Enter a decimal number: ");
   scanf("%d", &dec);
   
   printf("The hexadecimal equivalent of %d is: ", dec);
   convertToHex(dec);
   printf("\n");
   return 0;
}
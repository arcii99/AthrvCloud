//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>

char hexVals[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void convertToHex(int num) {
   int quotient;
   char hexadecimal[50];
   int i, j = 0;

   quotient = num;

   while (quotient != 0) {
      hexadecimal[j++] = hexVals[quotient % 16];
      quotient /= 16;
   }

   printf("Hexadecimal equivalent of the number is: ");

   for (i = j-1; i >= 0; i--)
      printf("%c", hexadecimal[i]);

   printf("\n");
}

int main(void) {
   int num;

   printf("Enter a decimal number: ");
   scanf("%d", &num);

   convertToHex(num);

   return 0;
}
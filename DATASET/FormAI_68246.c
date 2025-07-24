//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
   char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
   int decimal, rem, i = 0;
   char hexadecimal[20];

   printf("Welcome to the Hexadecimal Converter!\n");
   printf("Please enter a decimal number: ");
   scanf("%d", &decimal);

   while(decimal != 0) {
      rem = decimal % 16;
      hexadecimal[i] = hex[rem];
      i++;
      decimal = decimal / 16;
   }
   printf("The hexadecimal value of the entered decimal number is: ");
   for(int j=i-1; j>=0; j--) {
      printf("%c", hexadecimal[j]);
   }

   printf("\nThanks for using our converter, come back again soon!\n");
   return 0;
}
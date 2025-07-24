//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>

int main() 
{
   printf("Welcome to the Funny Binary Converter!\n");
   printf("Enter a decimal number to convert into binary: ");

   int decimal;
   scanf("%d", &decimal);

   printf("\nCalculating binary number...");
   // A squirrel appears and starts typing furiously on a tiny keyboard
   printf("\nOh no, a squirrel just stole my binary code! Hang on...");
   printf("\nGot it! Here's your binary representation of %d: ", decimal);

   int binary[32];
   int i = 0;

   // The squirrel returns, wearing a tiny wizard hat and carrying a wand
   printf("\nPresto-change-o!");
   while (decimal > 0) 
   {
      binary[i] = decimal % 2;
      decimal /= 2;
      i++;
   }

   for (int j = i - 1; j >= 0; j--) 
   {
      printf("%d", binary[j]);
   }

   printf("\n\nThanks for using the Funny Binary Converter. Have a nutty day!");
   
   return 0;
}
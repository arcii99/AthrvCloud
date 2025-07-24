//FormAI DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_converter(int number) {
   int binary_number[32], i = 0;
   while(number > 0) {
      binary_number[i] = number % 2;
      number = number / 2;
      i++;
   }
   for(int j = i - 1; j >= 0; j--)
      printf("%d",binary_number[j]);
}

int main() {
   printf("Welcome to the C Binary Converter program!\n");
   printf("This program will convert a decimal number to a binary number.\n");

   int num;
   char s[10];

   while(1) {
      printf("Enter the decimal number you would like to convert (or 'exit' to quit): ");
      fgets(s, sizeof(s), stdin);

      if(strcmp(s, "exit\n") == 0) {
         break;
      } else {
         sscanf(s, "%d", &num);
         printf("Your decimal number: %d\n", num);
         printf("Your binary number: ");
         binary_converter(num);
         printf("\n");
      }
   }

   printf("Thank you for using the C Binary Converter program!\n");

   return 0;
}
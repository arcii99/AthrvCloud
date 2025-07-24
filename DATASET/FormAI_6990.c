//FormAI DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num, i, j, bin[32];
   printf("Welcome to the Binary Converter! Please enter the decimal number you would like to convert: ");
   scanf("%d", &num);

   // Convert decimal to binary
   for(i=0; num>0; i++) {
       bin[i] = num%2;
       num = num/2;
   }

   // Print binary number
   printf("The binary representation of the decimal number is:\n");
   for(j=i-1; j>=0; j--)
      printf("%d", bin[j]);

   printf("\nDo you want to convert another number? (y/n): ");
   char choice;
   scanf(" %c", &choice);

   while(choice == 'y' || choice == 'Y') {
       system("clear"); // Clear console for cleaner view
       printf("Please enter the decimal number you would like to convert: ");
       scanf("%d", &num);

       for(i=0; num>0; i++) {
           bin[i] = num%2;
           num = num/2;
       }

       printf("\nThe binary representation of the decimal number is:\n");
       for(j=i-1; j>=0; j--)
          printf("%d", bin[j]);

       printf("\nDo you want to convert another number? (y/n): ");
       scanf(" %c", &choice);
   }
   
   printf("Thank you for using the Binary Converter! Goodbye!");
   return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include<stdio.h>

// Function to convert decimal to hexadecimal
void decToHex(int decnum) {
   // Array to store hexadecimal number
   char hexaDeciNum[100];
   
   // Counter for hexadecimal number array
   int i = 0;
   
   while(decnum!=0) {
      // Temporary variable to store remainder
      int temp  = 0;
      
      // Store remainder as hexadecimal equivalent
      temp = decnum % 16;
      
      if(temp < 10) {
         hexaDeciNum[i] = temp + 48;
         i++;
      } else {
         hexaDeciNum[i] = temp + 55;
         i++;
      }
      
      decnum = decnum/16;
   }
   
   // Printing hexadecimal number array in reverse order
   printf("The hexadecimal number is: ");
   
   for(int j=i-1; j>=0; j--)
      printf("%c", hexaDeciNum[j]);
}

// Main function for user input
int main() {
   int decimal; // User input decimal number
   
   printf("Enter a decimal number: ");
   scanf("%d", &decimal);
   
   // Call the function to convert decimal to hexadecimal
   decToHex(decimal);
   
   return 0;
}
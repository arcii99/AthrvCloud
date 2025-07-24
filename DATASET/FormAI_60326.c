//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert decimal to binary 
int decimalToBinary(int decimalNum) 
{ 
   int binaryNum = 0; 
   int rem, i = 1; 

   while (decimalNum != 0) 
   { 
      rem = decimalNum % 2; 
      decimalNum /= 2; 
      binaryNum += rem * i; 
      i *= 10; 
   } 

   return binaryNum; 
} 

// Function to convert binary to decimal 
int binaryToDecimal(int binaryNum) 
{ 
   int decimalNum = 0, i = 0, rem; 

   while (binaryNum != 0) 
   { 
      rem = binaryNum % 10; 
      binaryNum /= 10; 
      decimalNum += rem * pow(2, i); 
      ++i; 
   } 

   return decimalNum; 
} 

int main() 
{ 
   int num; 
   printf("Enter a decimal number: "); 
   scanf("%d", &num); 

   int binary = decimalToBinary(num); 
   printf("Binary representation of %d is %d\n", num, binary); 

   printf("Enter a binary number: "); 
   scanf("%d", &num); 

   int decimal = binaryToDecimal(num); 
   printf("Decimal representation of %d is %d\n", num, decimal); 

   return 0; 
}
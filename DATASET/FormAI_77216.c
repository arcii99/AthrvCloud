//FormAI DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include<stdio.h>
#include<math.h>

int decimalToBinary(int decimalNumber);

int main(){
  int decimalNumber;
  printf("Enter a decimal number: ");
  scanf("%d",&decimalNumber); 
  if(decimalNumber >= 0){
    printf("\nBinary representation of %d is: %d",decimalNumber, decimalToBinary(decimalNumber));
  }
  else{
    printf("\nCannot convert negative numbers to binary. Please enter a positive decimal number.");
  }
  return 0;
}

int decimalToBinary(int decimalNumber){
  int binaryNumber = 0, exponent = 0;
  while(decimalNumber > 0){
    binaryNumber += (decimalNumber%2) * pow(10,exponent);
    decimalNumber /= 2;
    exponent++;
  }
  return binaryNumber;
}
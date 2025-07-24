//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void toBinary(int decimalNum) {
  
  int binaryNum[32];
  
  int i = 0;
  
  while (decimalNum > 0) {
    
    binaryNum[i] = decimalNum % 2;
    
    decimalNum = decimalNum / 2;
    
    i++;
  }
  
  for (int j = i - 1; j >= 0; j--) {
    
    printf("%d", binaryNum[j]);
  }
}

int main() {
  
  printf(" **** Welcome to the Binary Number Converter **** \n\n");
  
  int decimalNum;
  
  printf("Please enter the decimal number you want to convert: \n");
  
  scanf("%d", &decimalNum);
  
  if (decimalNum >= 0) {
    
    printf("\n The binary equivalent of %d is: ", decimalNum);
    
    toBinary(decimalNum);
    
    printf("\n\n Thank you for using the Binary Number Converter! Have a great day! :)");
    
  } else {
    
    printf("\n Error: Please enter a positive decimal number.");
    
    return 0;
  }
}
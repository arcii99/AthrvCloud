//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {

  int num, binaryNum[64], tempNum;
  char option;

  printf("Welcome to the C Binary Converter!\n");
  
  do {
    printf("\nEnter a decimal number to convert to binary: ");
    scanf("%d", &num);
    
    tempNum = num;
    
    int i = 0;
    while (tempNum > 0) {
      binaryNum[i] = tempNum % 2;
      tempNum = tempNum / 2;
      i++;
    }
    
    printf("\nBinary conversion of the number is: ");
    
    int j = i - 1;
    while (j >= 0) {
      printf("%d", binaryNum[j]);
      j--;
    }
    
    printf("\n\nDo you want to convert another decimal number? (y/n): ");
    scanf(" %c", &option);
    
    if (option == 'n'){
      printf("\nThank you for using our C Binary Converter!");
    }
    
  } while (option != 'n');

  return 0;
}
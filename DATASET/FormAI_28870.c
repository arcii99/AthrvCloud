//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100], output[100];
  int num, temp, hex;
  
  printf("Enter a decimal number: ");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = '\0';
  
  num = atoi(input);
  
  if (num < 0) {
    printf("Invalid input. Number must be positive.\n");
    return 1;
  }
  
  temp = num;
  hex = 0;
  
  while (temp != 0) {
    hex += (temp % 16);
    temp /= 16;
  }
  
  if (hex < 10) {
    sprintf(output, "The decimal number %d is equal to %d in hexadecimal.", num, hex);
  } else {
    switch (hex) {
      case 10:
        sprintf(output, "The decimal number %d is equal to A in hexadecimal.", num);
        break;
      case 11:
        sprintf(output, "The decimal number %d is equal to B in hexadecimal.", num);
        break;
      case 12:
        sprintf(output, "The decimal number %d is equal to C in hexadecimal.", num);
        break;
      case 13:
        sprintf(output, "The decimal number %d is equal to D in hexadecimal.", num);
        break;
      case 14:
        sprintf(output, "The decimal number %d is equal to E in hexadecimal.", num);
        break;
      case 15:
        sprintf(output, "The decimal number %d is equal to F in hexadecimal.", num);
        break;
      default:
        break;
    }
  }
  
  printf("%s\n", output);
  
  return 0;
}
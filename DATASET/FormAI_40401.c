//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Cryptic style C program for Hexadecimal Conversion

int main() {

  int num;
  char hex[10];
  int i = 0;

  printf("Enter the number to be converted: ");
  scanf("%d", &num);

  while(num > 0) {
    int rem = num % 16;

    if (rem < 10) {
      hex[i] = rem + 48;
      i++;
    }
    else {
      hex[i] = rem + 55;
      i++;
    }

    num = num / 16;
  }

  printf("Hexadecimal conversion is: ");

  for(int j = i - 1; j >= 0; j--) {
    printf("%c", hex[j]);
  }

  return 0;

}
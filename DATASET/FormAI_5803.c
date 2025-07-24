//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>

void convertToHex(char str[], int n);
int isValid(char str[], int n);

int main() {
  char str[1000];
  
  printf("Enter a decimal number: ");
  scanf("%s", str);

  int n = strlen(str);

  if (!isValid(str, n)) {
    printf("Invalid decimal number\n");
    return 0;
  }

  convertToHex(str, n);

  return 0;
}

void convertToHex(char str[], int n) {
  int decimal = 0;
  int power = 1;
  
  for (int i = n - 1; i >= 0; i--) {
    decimal += (str[i] - '0') * power;
    power *= 10;
  }
  
  printf("Hexadecimal: 0x%X\n", decimal);
}

int isValid(char str[], int n) {
  for (int i = 0; i < n; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  
  return 1;
}
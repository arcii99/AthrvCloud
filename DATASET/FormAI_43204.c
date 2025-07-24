//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the cyberpunk hexadecimal converter!\n");
  printf("Enter a decimal number to convert to hexadecimal: ");

  char input[10];
  fgets(input, 10, stdin); // read user input

  int num = atoi(input); // convert string input to integer
  int max_digits = 10;
  char hex[max_digits]; // initialize hex array to store hexadecimal digits

  int remainder;
  int index = 0; // index to keep track of current digit in hex array

  while (num > 0 && index < max_digits) {
    remainder = num % 16; // get remainder after dividing by 16
    if (remainder < 10) {
      hex[index] = remainder + '0'; // add 0-9 digit to hex array
    } else {
      hex[index] = remainder + 55; // add A-F digit to hex array
    }
    index++;
    num /= 16; // divide num by 16 to get next digit
  }

  printf("Hexadecimal representation of %d: ", num);
  for (int i = index - 1; i >= 0; i--) {
    printf("%c", hex[i]); // print hexadecimal digits backwards
  }
  printf("\n");

  return 0;
}
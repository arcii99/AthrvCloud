//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_DECIMAL_DIGITS 10
#define MAX_HEX_DIGITS 8
#define TRUE 1
#define FALSE 0

int valid_hex_input(char input) {
  if(isxdigit(input)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void paranoid_clear_input() {
  char ch;
  while ((ch = getchar()) != '\n'&& ch != EOF);
}

int decimal_to_hexadecimal(int decimal_number) {
  int i = 0, remainder = 0;
  char hexadecimal_number[MAX_HEX_DIGITS];

  while(decimal_number != 0) {
    remainder = decimal_number % 16;
    if(remainder < 10) {
      hexadecimal_number[i++] = 48 + remainder;
    }
    else {
      hexadecimal_number[i++] = 55 + remainder;
    }
    decimal_number = decimal_number / 16;
  }

  printf("The equivalent hexadecimal value of the decimal number is: 0x");

  for(int j = i - 1; j >= 0; j--) {
    printf("%c", hexadecimal_number[j]);
  }

  printf("\n");
}

int main() {
  char input_decimal_string[MAX_DECIMAL_DIGITS];
  int decimal_number, valid_input = FALSE;

  printf("This program converts a decimal value to its hexadecimal equivalent.\n\n");

  while(!valid_input) {
    printf("Please enter a valid decimal value between 0 and 4294967295: ");
    fgets(input_decimal_string, MAX_DECIMAL_DIGITS, stdin);
    if(input_decimal_string[0] == '\n') {
      paranoid_clear_input();
    }
    else {
      decimal_number = atoi(input_decimal_string);
      if(decimal_number >= 0 && decimal_number <= 4294967295) {
        valid_input = TRUE;
      }
      else {
        printf("Invalid input. Please enter a valid decimal value.\n");
      }
    }
  }

  decimal_to_hexadecimal(decimal_number);

  return 0;
}
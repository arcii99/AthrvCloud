//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hex_to_binary(char *hex_val);
int hex_to_dec(char *hex_val);
char *dec_to_binary(int dec_val);
int binary_to_dec(char *binary_val);
char *binary_to_hex(char *binary_val);

int main() {
  char hex_input[10];
  char *binary_output = NULL;
  int decimal_output;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_input);

  binary_output = hex_to_binary(hex_input);
  decimal_output = hex_to_dec(hex_input);

  printf("The binary equivalent of %s is: %s\n", hex_input, binary_output);
  printf("The decimal equivalent of %s is: %d\n", hex_input, decimal_output);

  free(binary_output);
  binary_output = NULL;

  int decimal_input;
  char *binary_input = NULL;
  char *hex_output = NULL;
  char choice;

  printf("Do you want to convert a decimal number to binary and hexadecimal? (y/n): ");
  scanf(" %c", &choice);

  if (choice == 'y') {
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_input);

    binary_input = dec_to_binary(decimal_input);
    hex_output = binary_to_hex(binary_input);

    printf("The binary equivalent of %d is: %s\n", decimal_input, binary_input);
    printf("The hexadecimal equivalent of %d is: %s\n", decimal_input, hex_output);

    free(binary_input);
    binary_input = NULL;
    free(hex_output);
    hex_output = NULL;
  }

  return 0;
}

// Function to convert hexadecimal to binary
char *hex_to_binary(char *hex_val) {
  int len = strlen(hex_val);

  char *binary_val = malloc((4 * len + 1) * sizeof(char));
  binary_val[4 * len] = '\0';

  for (int i = 0; i < len; i++) {
    switch (hex_val[i]) {
      case '0': strcpy(binary_val + 4 * i, "0000"); break;
      case '1': strcpy(binary_val + 4 * i, "0001"); break;
      case '2': strcpy(binary_val + 4 * i, "0010"); break;
      case '3': strcpy(binary_val + 4 * i, "0011"); break;
      case '4': strcpy(binary_val + 4 * i, "0100"); break;
      case '5': strcpy(binary_val + 4 * i, "0101"); break;
      case '6': strcpy(binary_val + 4 * i, "0110"); break;
      case '7': strcpy(binary_val + 4 * i, "0111"); break;
      case '8': strcpy(binary_val + 4 * i, "1000"); break;
      case '9': strcpy(binary_val + 4 * i, "1001"); break;
      case 'A': strcpy(binary_val + 4 * i, "1010"); break;
      case 'B': strcpy(binary_val + 4 * i, "1011"); break;
      case 'C': strcpy(binary_val + 4 * i, "1100"); break;
      case 'D': strcpy(binary_val + 4 * i, "1101"); break;
      case 'E': strcpy(binary_val + 4 * i, "1110"); break;
      case 'F': strcpy(binary_val + 4 * i, "1111"); break;
      default: {
        printf("Invalid hexadecimal input. Exiting program...\n");
        exit(-1);
      }
    }
  }

  return binary_val;
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex_val) {
  int len = strlen(hex_val);
  int dec_val = 0;

  for (int i = 0; i < len; i++) {
    int digit_value = 0;
    switch (hex_val[i]) {
      case '0': digit_value = 0; break;
      case '1': digit_value = 1; break;
      case '2': digit_value = 2; break;
      case '3': digit_value = 3; break;
      case '4': digit_value = 4; break;
      case '5': digit_value = 5; break;
      case '6': digit_value = 6; break;
      case '7': digit_value = 7; break;
      case '8': digit_value = 8; break;
      case '9': digit_value = 9; break;
      case 'A': digit_value = 10; break;
      case 'B': digit_value = 11; break;
      case 'C': digit_value = 12; break;
      case 'D': digit_value = 13; break;
      case 'E': digit_value = 14; break;
      case 'F': digit_value = 15; break;
      default: {
        printf("Invalid hexadecimal input. Exiting program...\n");
        exit(-1);
      }
    }
    dec_val += digit_value * (1 << (4 * (len - i - 1)));
  }

  return dec_val;
}

// Function to convert decimal to binary
char *dec_to_binary(int dec_val) {
  int len = 0;
  int temp = dec_val;

  while (temp > 0) {
    temp /= 2;
    len++;
  }

  if (len == 0) {
    char *result = malloc(2 * sizeof(char));
    result[0] = '0';
    result[1] = '\0';
    return result;
  }

  char *binary_val = malloc((len + 1) * sizeof(char));
  binary_val[len] = '\0';

  for (int i = len - 1; i >= 0; i--) {
    binary_val[i] = (dec_val % 2) + '0';
    dec_val /= 2;
  }

  return binary_val;
}

// Function to convert binary to decimal
int binary_to_dec(char *binary_val) {
  int len = strlen(binary_val);
  int dec_val = 0;

  for (int i = 0; i < len; i++) {
    dec_val += (binary_val[len - i - 1] - '0') * (1 << i);
  }

  return dec_val;
}

// Function to convert binary to hexadecimal
char *binary_to_hex(char *binary_val) {
  int len = strlen(binary_val);
  int num_of_digits = len / 4;
  if (len % 4 > 0) {
    num_of_digits++;
  }

  char *hex_val = malloc((num_of_digits + 1) * sizeof(char));
  hex_val[num_of_digits] = '\0';

  for (int i = num_of_digits - 1; i >= 0; i--) {
    int digit_value = 0;
    for (int j = 0; j < 4; j++) {
      int index = i * 4 + j + len % 4;
      if (index < len) {
        digit_value += (binary_val[len - index - 1] - '0') * (1 << j);
      }
    }
    switch (digit_value) {
      case 0: hex_val[i] = '0'; break;
      case 1: hex_val[i] = '1'; break;
      case 2: hex_val[i] = '2'; break;
      case 3: hex_val[i] = '3'; break;
      case 4: hex_val[i] = '4'; break;
      case 5: hex_val[i] = '5'; break;
      case 6: hex_val[i] = '6'; break;
      case 7: hex_val[i] = '7'; break;
      case 8: hex_val[i] = '8'; break;
      case 9: hex_val[i] = '9'; break;
      case 10: hex_val[i] = 'A'; break;
      case 11: hex_val[i] = 'B'; break;
      case 12: hex_val[i] = 'C'; break;
      case 13: hex_val[i] = 'D'; break;
      case 14: hex_val[i] = 'E'; break;
      case 15: hex_val[i] = 'F'; break;
    }
  }

  return hex_val;
}
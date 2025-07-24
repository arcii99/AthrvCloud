//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>

int main() {
  // Declare a variable to hold the decimal input
  int decimal_input;
  
  // Prompt the user to enter a decimal number
  printf("Enter a decimal number: ");
  scanf("%d", &decimal_input);
  
  // Convert the decimal input to hexadecimal and store in a string
  char hex_output[50];
  snprintf(hex_output, sizeof(hex_output), "%X", decimal_input);
  
  // Print the result to the console
  printf("The decimal number %d in hexadecimal is %s\n", decimal_input, hex_output);
  
  return 0;
}
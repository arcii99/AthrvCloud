//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
  // Greeting message
  printf("Welcome to the Hex Converter!\n");

  while (1) {
    // Prompt user to enter decimal number
    printf("Enter a decimal number (Q to quit): ");
    char input[10];
    scanf("%s", input);

    // Check if user wants to quit
    if (input[0] == 'Q') {
      printf("Goodbye!\n");
      break;
    }

    // Convert decimal to hexadecimal
    int decimal = atoi(input);
    printf("Hexadecimal equivalent: %X\n", decimal);
  }

  return 0;
}
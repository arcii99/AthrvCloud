//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Binary Converter!\n");
  printf("Enter a decimal number and I'll convert it to binary:\n");
  int decimal;
  scanf("%d", &decimal);
  
  printf("\nCalculating. Please wait...\n");

  // In order to convert to binary, we need to keep dividing the decimal number by 2
  // until we reach 0
  int binary[100]; // We'll store the binary digits in an array
  int i = 0; // Index for the binary array
  while(decimal != 0) {
    binary[i] = decimal % 2; // Get the remainder
    decimal = decimal / 2; // Divide by 2
    i++; // Move to the next index
  }

  printf("\nDone! Here's your number in binary:\n");
  for(int j = i - 1; j >= 0; j--) { // Print the binary digits in reverse order
    printf("%d", binary[j]);
  }

  printf("\n\nI hope you found this useful!\n");
  printf("For more exciting programming adventures, come back soon!");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the Binary Converter!\n\n");

  // User input
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Binary conversion
  int binary[32];
  int i = 0;
  while (decimal > 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }
  
  // Output binary number
  printf("Binary equivalent: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n\n");

  // Play again option
  char playAgain;
  printf("Would you like to convert another decimal number? (Y/N) ");
  scanf(" %c", &playAgain);
  if (playAgain == 'Y' || playAgain == 'y') {
    // Clear screen and start over
    system("clear");
    main();
  } else {
    printf("Thanks for using the Binary Converter!\n");
  }
  
  return 0;
}
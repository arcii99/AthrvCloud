//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to my C Binary Converter!! Let's get started!\n\n");
  
  // Define our variables
  int decimal, binary[32], i = 0;
  
  // Get input from user
  printf("Enter a positive integer: ");
  scanf("%d", &decimal);
  
  // Convert the decimal to binary and store in array
  while (decimal > 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }
  
  // Output the binary number
  printf("\nHere is your binary number: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n\n");
  
  // Party time!!
  printf("Woohoo! You did it!! Time to celebrate with some celebratory code!\n\n");
  
  // Display some celebratory code
  for (int k = 0; k < 5; k++) {
    printf("printf(\"You're awesome, keep up the good work!\\n\");\n");
  }
  
  printf("\n\nYay! You're officially a binary converting superstar!! Come back soon!\n");
  
  return 0;
}
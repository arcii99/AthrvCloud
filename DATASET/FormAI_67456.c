//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  srand(time(0)); // Initializes random number generator with current timestamp
  int code[25]; // We will store the code in an array of integers
  
  // Let's generate the code
  for (int i = 0; i < 25; i++) {
    code[i] = rand() % 10; // Generates a random integer between 0 and 9 inclusive
  }
  
  // Let's print the code in QR format
  printf("QR Code: \n\n");
  printf("███      ███  ██████████  ███      ███\n");
  printf("███      ███  ███    ███  ███      ███\n");
  printf("███      ███  ███    ███  ███      ███\n");
  printf(" ██████████   ██████████  ██████████\n");
  printf("         ███          ███          ███\n");
  printf("         ███          ███          ███\n");
  printf("         ███          ███          ███\n");
  printf("         ███          ███          ███\n");
  
  for (int i = 0; i < 5; i++) {
    printf("\n"); // Adds some space between the lines
    for (int j = 0; j < 5; j++) {
      printf("  █ "); // Prints a black square
      if (code[i*5+j] % 2 == 0) {
        printf("  "); // Prints a white square for even numbers
      } else {
        printf("██"); // Prints a black square for odd numbers
      }
    }
    printf("  █ "); // Prints the closing black square for the line
  }
  
  printf("\n\nCode: ");
  for (int i = 0; i < 25; i++) {
    printf("%d", code[i]); // Prints the code as a string of numbers
  }
  printf("\n");
  
  return 0;
}
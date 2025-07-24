//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to convert a character to its ASCII art representation
void asciiArt(char c) {
  switch(c) {
    case 'A':
      printf("  /\\  \n /  \\ \n/____\\\n");
      break;
    case 'B':
      printf(" ____  \n| __ ) \n|  _ \\ \n| |_) |\n|____/ \n");
      break;
    case 'C':
      printf("  ____ \n / ___|\n| |    \n| |___ \n \\____|\n");
      break;
    // Add cases for the rest of the alphabet
    // ...
    default:
      printf("      \n      \n      \n      \n      \n");
      break;
  }
}

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  int length = strlen(str);

  for(int i = 0; i < length; i++) {
    asciiArt(str[i]);
    printf("\n");
  }

  return 0;
}
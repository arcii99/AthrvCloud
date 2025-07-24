//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>

int main() {
  char input[50];
  printf("Enter text to convert to ASCII art: ");
  scanf("%s", input);

  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    switch(c) {
      case 'A':
        printf("    /\\  \n   /  \\ \n  /____\\\n /      \\\n/        \\\n");
        break;
      case 'B':
        printf(" ______\n|  ____\\\n| |___\n|___  \\\n ____) |\n|_____/ \n");
        break;
      case 'C':
        printf("  _____  \n / ____| \n| |  \n| |  \n| |____\n \\_____|\n");
        break;
      case 'D':
        printf(" _____ \n|  __ \\\n| |  \\\n| |  |\n| |__/\n|_____\n");
        break;
      case 'E':
        printf(" ______\n|  ____|\n| |__\n|  __|\n| |____\n|______|\n");
        break;
      case 'F':
        printf(" ______\n|  ____|\n| |__ \n|  __|\n| |  \n|_|  \n");
        break;
      // continue with more letters, numbers, and symbols
      default:
        printf("    \n\n\n\n\n\n");
    }
  }

  return 0;
}
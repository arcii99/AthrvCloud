//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>

int main() {
  char input[1000];

  printf("Enter some text: ");
  fgets(input, sizeof(input), stdin);

  int length = 0;
  while (input[length] != '\0') {
    length++;
  }

  printf("\nASCII art:\n");

  for (int i = 0; i < length; i++) {
    char c = input[i];
    switch (c) {
      case 'A':
        printf("      /\\\n");
        printf("     /  \\\n");
        printf("    / /\n");
        printf("   / /__\n");
        printf("  / ____\\\n");
        printf(" / /\n");
        printf("/_/     \\\n");
        break;

      case 'B':
        printf(" ____\n");
        printf("|  _ \\\n");
        printf("| |_) |\n");
        printf("|  _ <\n");
        printf("| |_) |\n");
        printf("|____/\n");
        break;

      case 'C':
        printf("  ____\n");
        printf(" / ___\\\n");
        printf("/ /    \n");
        printf("\\ \\___ \n");
        printf(" \\____\\\n");
        break;

      // Add more characters here as desired

      default:
        printf("   /\n");
        printf("  /  \\\n");
        printf(" /    \\\n");
        printf("/______\\\n");
        break;
    }
  }

  return 0;
}
//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
  printf("Codenet CyberWarriors, let's infiltrate the system with our string manipulation skills!\n");

  char code[] = "r5tTgv3!e^F";

  // Reverse the string
  printf("First we need to reverse the code: ");
  int length = strlen(code);
  for (int i = length - 1; i >= 0; i--) {
    printf("%c", code[i]);
  }
  printf("\n");

  // Replace vowels with numbers
  printf("Now, we need to replace the vowels with numbers: ");
  for (int i = 0; i < length; i++) {
    char c = code[i];
    switch (c) {
      case 'a':
        printf("4");
        break;
      case 'e':
        printf("3");
        break;
      case 'i':
        printf("1");
        break;
      case 'o':
        printf("0");
        break;
      case 'u':
        printf("6");
        break;
      default:
        printf("%c", c);
        break;
    } 
  }
  printf("\n");

  // Make the first letter uppercase
  printf("Finally, we'll make the first letter uppercase: ");
  code[0] = toupper(code[0]);
  printf("%s", code);

  printf("\nWe did it! The code has been transformed into an uncrackable cyber password!\n");

  return 0;
}
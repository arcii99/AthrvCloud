//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: intelligent
#include<stdio.h>
#include<string.h>

// function to convert given character to ASCII art
void toAscii(char c) {
  switch (c) {
    case 'A':
      printf("  /\\  \n /  \\ \n/    \\\n/------\\\n/      \\\n");
      break;
    case 'B':
      printf("------\n|     \\\n|-----/\n|     \\\n------/\n");
      break;
    case 'C':
      printf("  -----\n /     \\\n/       \n\\       \n \\     /\n  -----\n");
      break;
    // add more cases here for all uppercase letters
    // you can also add cases for digits and special characters
    default:
      printf("    \n    \n    \n___ \n    |\n    |\n");
      break;
  }
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%[^\n]", str);  // input string with spaces using scanf

  printf("\nASCII ART:\n");
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    toAscii(str[i]);
  }

  return 0;
}
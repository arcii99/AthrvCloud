//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>

int main() {
  char input[100], output[100], ch;
  int i, len, shift;

  printf("Enter text to be encrypted: ");
  fgets(input, 100, stdin);

  printf("Enter shift: ");
  scanf("%d", &shift);

  len = strlen(input);

  for (i = 0; i < len; i++) {
    ch = input[i];

    //encrypt uppercase letters
    if (ch >= 'A' && ch <= 'Z') {
      ch = (ch + shift - 'A') % 26 + 'A';
    }

    //encrypt lowercase letters
    else if (ch >= 'a' && ch <= 'z') {
      ch = (ch + shift - 'a') % 26 + 'a';
    }

    output[i] = ch;
  }

  printf("Encrypted text: %s\n", output);

  return 0;
}
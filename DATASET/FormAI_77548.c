//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a sentence in C Cat Language: ");
  fgets(input, 100, stdin);

  int i, j, vowels = 0;
  for (i = 0; input[i] != '\0'; ++i) {
    char c = input[i];

    // Check for vowels
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      ++vowels;

    // Translate 'meow' to 'printf'
    if (c == 'm' && input[i + 1] == 'e' && input[i + 2] == 'o' && input[i + 3] == 'w') {
      printf("printf");
      i += 3;
    } else {  // Output the original character
      putchar(c);
    }
  }

  printf("\nVowels: %d", vowels);

  return 0;
}
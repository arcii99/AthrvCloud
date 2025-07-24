//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100];
  printf("Enter a sentence to analyze: ");
  fgets(input, 100, stdin);

  int vowels = 0, consonants = 0, digits = 0, whitespace = 0, symbols = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    char c = tolower(input[i]);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowels++;
    } else if (c >= 'a' && c <= 'z') {
      consonants++;
    } else if (isdigit(c)) {
      digits++;
    } else if (isspace(c)) {
      whitespace++;
    } else {
      symbols++;
    }
  }

  printf("\nAnalysis of the sentence:\n");
  printf("Vowels: %d\n", vowels);
  printf("Consonants: %d\n", consonants);
  printf("Digits: %d\n", digits);
  printf("Whitespace: %d\n", whitespace);
  printf("Symbols: %d\n", symbols);

  return 0;
}
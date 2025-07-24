//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  int vowels = 0, consonants = 0, digits = 0, spaces = 0;

  printf("Enter a string (less than 100 characters): ");
  fgets(text, sizeof(text), stdin);

  // Loop through the string
  for (int i = 0; i < strlen(text); i++) {
    // Check if the character is a vowel or consonant
    if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
        text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
      vowels++;
    }
    else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
      consonants++;
    }
    else if (text[i] >= '0' && text[i] <= '9') {
      digits++;
    }
    else if (text[i] == ' ') {
      spaces++;
    }
  }

  printf("\nString analysis:\n");
  printf("----------------\n");
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
  printf("Number of digits: %d\n", digits);
  printf("Number of spaces: %d\n", spaces);

  return 0;
}
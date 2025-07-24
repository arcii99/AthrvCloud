//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  int vowels = 0, consonants = 0, digits = 0, spaces = 0;

  printf("Enter the string: ");
  fgets(string, 100, stdin); // read the input string from user

  int length = strlen(string);

  for (int i = 0; i < length; i++) {
    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
        string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
      vowels++;
    } else if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
      consonants++;
    } else if (string[i] >= '0' && string[i] <= '9') {
      digits++;
    } else if (string[i] == ' ') {
      spaces++;
    }
  }

  printf("\nAnalysis of the input string:\n\n");
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
  printf("Number of digits: %d\n", digits);
  printf("Number of spaces: %d\n", spaces);

  return 0;
}
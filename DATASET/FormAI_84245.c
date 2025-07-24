//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int vowels = 0, consonants = 0, digits = 0, spaces = 0;

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      spaces++;
    } else if (isdigit(str[i])) {
      digits++;
    } else if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      vowels++;
    } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
      consonants++;
    }
  }

  printf("\nInput string: %s", str);
  printf("\nNumber of vowels: %d", vowels);
  printf("\nNumber of consonants: %d", consonants);
  printf("\nNumber of digits: %d", digits);
  printf("\nNumber of spaces: %d", spaces);

  return 0;
}
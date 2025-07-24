//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int i, vowels = 0, consonants = 0, digits = 0, spaces = 0;
 
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
 
  for (i = 0; i < strlen(str); i++) {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
        vowels++;
      } else {
        consonants++;
      }
    } else if (str[i] >= '0' && str[i] <= '9') {
      digits++;
    } else if (str[i] == ' ') {
      spaces++;
    }
  }
 
  printf("\nString: \"%s\"", str);
  printf("\nVowels: %d", vowels);
  printf("\nConsonants: %d", consonants);
  printf("\nDigits: %d", digits);
  printf("\nSpaces: %d", spaces);
 
  return 0;
}
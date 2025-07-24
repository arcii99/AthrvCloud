//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
  char str[100], vowel[100];
  int i, j, vowel_count = 0;

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  for (i = 0; i < strlen(str); i++) { // loop through the string character by character
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      vowel[vowel_count++] = str[i]; // if the character is a vowel, add it to the vowel array
    }
  }

  printf("Vowels in string: %s\n", vowel);

  return 0;
}
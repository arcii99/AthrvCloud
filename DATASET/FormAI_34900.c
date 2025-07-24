//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
  char string[1000];
  printf("Enter a string: ");
  fgets(string, sizeof(string), stdin); // read input from user
  int length = strlen(string); // get length of input string
  int numVowels = 0, numConsonants = 0, numSpaces = 0, numDigits = 0, numOthers = 0;
  for (int i = 0; i < length; i++) {
    char c = string[i];
    if (c >= 'A' && c <= 'Z') {
      c = c + ('a' - 'A'); // convert uppercase letter to lowercase
    }
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      numVowels++;
    } else if (c >= 'a' && c <= 'z') {
      numConsonants++;
    } else if (c == ' ') {
      numSpaces++;
    } else if (c >= '0' && c <= '9') {
      numDigits++;
    } else {
      numOthers++;
    }
  }
  printf("Number of vowels: %d\n", numVowels);
  printf("Number of consonants: %d\n", numConsonants);
  printf("Number of spaces: %d\n", numSpaces);
  printf("Number of digits: %d\n", numDigits);
  printf("Number of other characters: %d\n", numOthers);
  return 0;
}
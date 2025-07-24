//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[1000], c;
  int frequency[26] = {0}, total_chars = 0;
  printf("Welcome to the Cheerful C Word Frequency Counter!\n");
  printf("Please enter a string of text (up to 1000 characters):\n");

  // Reading user input
  fgets(str, 1000, stdin);

  // Converting string to lowercase
  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = tolower(str[i]);
    }
  }

  // Counting the frequency of each alphanumeric character
  for(int i = 0; str[i] != '\0'; i++) {
    c = str[i];
    if(isalnum(c)) {
      frequency[c - 97]++;
      total_chars++;
    }
  }

  // Printing the frequency count of each character
  printf("\n\n********** Cheerful C Word Frequency Counter ***********\n\n");
  printf("Total characters: %d\n", total_chars);
  for(int i = 0; i < 26; i++) {
    if(frequency[i] != 0) {
      printf("%c: %d\n", i + 97, frequency[i]);
    }
  }

  printf("\n********** Have a nice day! ***********\n\n");
  return 0;
}
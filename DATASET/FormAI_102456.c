//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <ctype.h>

// Function to count number of words in a given string
int countWords(char string[]) {

  int count = 0, i;

  // Loop through each character in the string
  for (i = 0; string[i] != '\0'; i++) {

    // If current character is not a whitespace and next character is a whitespace or end of string, then it is a new word
    if (!isspace(string[i]) && (isspace(string[i+1]) || string[i+1] == '\0')) {
      count++;
    }
  }

  return count;
}

int main() {

  char string[100];

  // Get input string from user
  printf("Enter a string: ");
  fgets(string, 100, stdin);

  // Call countWords function and print the result
  printf("Number of words in the string: %d\n", countWords(string));

  return 0;
}
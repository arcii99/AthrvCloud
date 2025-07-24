//FormAI DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, length, count = 0;
  char inputString[100], outputString[100], word[20], replace[20];

  printf("Enter a string: ");
  fgets(inputString, sizeof(inputString), stdin);
  length = strlen(inputString);

  printf("Enter a word to replace: ");
  scanf("%s", word);

  printf("Enter a word to replace with: ");
  scanf("%s", replace);

  for(i = 0; i < length; i++) {
    if (inputString[i] == word[0]) {
      // check if word match found at current position
      for(j = i; j < length && inputString[j] == word[j-i]; j++);
      if (j - i == strlen(word)) {
        // match found, increment count and copy replace string
        count++;
        for (j = 0; j < strlen(replace); j++) {
          outputString[i+j] = replace[j];
        }
        i = i + strlen(word) - 1;
      } else {
        // no match found, copy original string
        outputString[i] = inputString[i];
      }
    } else {
      // copy original string
      outputString[i] = inputString[i];
    }
  }
  outputString[i] = '\0';

  if (count == 0) {
    printf("No words to replace!");
  } else {
    printf("Replaced %d occurrences of '%s' with '%s'.\n", count, word, replace);
    printf("Input: %s", inputString);
    printf("Output: %s", outputString);
  }
  return 0;
}
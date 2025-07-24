//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char sentence[1000], word[1000], ch;
  int frequency[50] = {0}, i = 0, j = 0, k = 0;

  printf("Enter a sentence:\n");
  fgets(sentence, sizeof(sentence), stdin);

  while (sentence[i] != '\0') {
    ch = sentence[i];

    if (isalpha(ch)) {
      word[j] = tolower(ch);
      j++;
    } 
    else if (isspace(ch) || ch == '.' || ch == ',') {
      word[j] = '\0';
      j = 0;

      for (k = 0; k < strlen(word); k++) {
        if (word[k] == 'c' || word[k] == 'C') {
          frequency[i]++;
        }
      }
      i++;
    }
  }

  printf("Word Frequency\n");
  printf("----------------\n");

  for (i = 0; i < 50; i++) {
    if (frequency[i] != 0) {
      printf("The letter C appears %d times in word %d.\n", frequency[i], i + 1);
    }
  }

  return 0;
}
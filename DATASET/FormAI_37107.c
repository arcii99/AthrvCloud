//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
  char text[1000], word[100], ch;
  int i = 0, j = 0, count = 0, word_count = 0;

  printf("Enter some text: ");
  fgets(text, sizeof(text), stdin);

  printf("\nEnter a word to search for: ");
  scanf("%s", word);

  while (text[i] != '\0') {
    ch = text[i];

    if (ch == ' ' || ch == '\n' || ch == '\t') {
      word_count = 0;
    } else {
      word_count++;
    }

    if (word[j] == ch) {
      j++;

      if (j == strlen(word)) {
        count++;
        j = 0;
      }
    } else {
      j = 0;
    }

    i++;
  }

  printf("\nThe word %s was found %d times.\n", word, count);

  return 0;
}
//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LENGTH 1000

int main() {
  char text[MAX_TEXT_LENGTH], word[MAX_TEXT_LENGTH];
  int word_frequency[MAX_TEXT_LENGTH], i, j, k, len_text, len_word, count;

  printf("Enter your text: ");
  fgets(text, MAX_TEXT_LENGTH, stdin);
  
  printf("\nWord frequencies:\n");

  len_text = strlen(text);
  len_word = 0;
  count = 0;
  j = 0;

  for (i = 0; i < len_text; i++) {
    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
      word[j] = '\0';
      len_word = strlen(word);
      count = 0;

      for (k = 0; k < len_word; k++) {
        if (word[k] == text[i]) {
          count++;
        }
      }

      for (k = 0; k < i; k++) {
        if (strcmp(word, &text[k]) == 0) {
          word_frequency[k]++;
          break;
        }
      }

      if (k == i) {
        strcpy(&text[j], word);
        word_frequency[j++] = 1;
        text[j++] = ' ';
      }

      j = 0;
    } else {
      word[j++] = text[i];
    }
  }

  for (i = 0; i < j; i++) {
    printf("%c", word[i]);
  }

  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == ' ') {
      printf(" - %d\n", word_frequency[i / 2]);
    }
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_TEXT_LENGTH 100

char *spam_words[MAX_SPAM_WORDS] = {"buy", "free", "limited", "promotion", "sale", "discount", "deal", "offer", "act now", "click here"};

int is_spam(char *text) {
  char *token;
  token = strtok(text, " ");

  while (token != NULL) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
      if (strcmp(token, spam_words[i]) == 0) {
        return 1;
      }
    }

    token = strtok(NULL, " ");
  }

  return 0;
}

int main() {
  char text[MAX_TEXT_LENGTH];

  printf("Enter some text:\n");
  fgets(text, MAX_TEXT_LENGTH, stdin);

  if (is_spam(text)) {
    printf("This text contains spam!\n");
  } else {
    printf("This text is not spam.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_SPAM_WORDS 10
#define MAX_SPAM_OCCURRENCES 3

char *spamWords[MAX_SPAM_WORDS] = {"money", "free", "guaranteed", "win", "prize", "offer", "limited", "discount", "earn", "cash"};

bool isSpam(char *message) {
  int count[MAX_SPAM_WORDS];
  memset(count, 0, sizeof(count)); // initialize all counts to 0

  char *tok = strtok(message, " ");

  while (tok != NULL) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
      if (strcmp(spamWords[i], tok) == 0) {
        count[i]++;
      }
    }
    tok = strtok(NULL, " ");
  }

  for (int i = 0; i < MAX_SPAM_WORDS; i++) {
    if (count[i] >= MAX_SPAM_OCCURRENCES) {
      return true;
    }
  }

  return false;
}

int main() {
  char message[MAX_MESSAGE_LENGTH];

  while (true) {
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    if (isSpam(message)) {
      printf("SPAM DETECTED!\n");
    } else {
      printf("Not spam.\n");
    }
  }

  return 0;
}
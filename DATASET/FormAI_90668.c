//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to check if word is a common spam keyword
int isSpam(char *word) {
  char *spamWords[] = {"buy", "cheap", "discount", "free", "limited time", "money back guarantee", "offer", "special promotion", "winner"};
  int numSpamWords = 9;
  int i;
  for (i = 0; i < numSpamWords; i++) {
    if (strcmp(word, spamWords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// function to scan and check if the message is spam or not
int checkMessage(char *message) {
  int i;
  char *word;
  int numWords = 0;
  char *copy = strdup(message);
  word = strtok(copy, " ");
  while (word != NULL) {
    if (isSpam(word)) {
      return 1;
    }
    numWords++;
    word = strtok(NULL, " ");
  }
  free(copy);
  return 0;
}

int main() {
  char message[1000];
  printf("Please enter your message: ");
  fgets(message, 1000, stdin);
  message[strlen(message)-1] = '\0';
  if (checkMessage(message)) {
    printf("The message contains spam.\n");
  } else {
    printf("The message is not spam.\n");
  }
  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define SPAM_THRESHOLD 0.5

int main() {
  char msg[MAX_MSG_LENGTH];
  int num_words = 0, num_spam_words = 0;

  // Prompt user for message input
  printf("Enter your message:\n");
  fgets(msg, MAX_MSG_LENGTH, stdin);

  // Count number of words in message
  char* token = strtok(msg, " ");
  while (token != NULL) {
    num_words++;
    token = strtok(NULL, " ");
  }

  // Check each word for spam keywords
  char* spam_words[] = {"money", "free", "offer", "discount", "act now", "limited time", "click here"};
  token = strtok(msg, " ");
  while (token != NULL) {
    for (int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
      if (strstr(token, spam_words[i]) != NULL) {
        num_spam_words++;
        break;
      }
    }
    token = strtok(NULL, " ");
  }

  // Calculate spam score and give verdict
  float spam_score = (float)num_spam_words / num_words;
  if (spam_score >= SPAM_THRESHOLD) {
    printf("This message is spam (spam score: %.2f %%)\n", spam_score * 100);
  } else {
    printf("This message is not spam (spam score: %.2f %%)\n", spam_score * 100);
  }

  return 0;
}
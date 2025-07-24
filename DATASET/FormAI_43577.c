//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct spam_detection_system {
  char message[100];
  int score;
  bool is_spam;
} spam_detection_system;

void check_spam(spam_detection_system *message) {
  // Check if message contains spam words
  char *spam_words[5] = {"spam", "free", "money", "guaranteed", "win"};
  for (int i = 0; i < 5; i++) {
      if (strstr(message->message, spam_words[i]) != NULL) {
        message->score += 10;
      }
  }

  // Check if message is all caps
  bool all_caps = true;
  for (int i = 0; i < strlen(message->message); i++) {
    if (message->message[i] >= 'a' && message->message[i] <= 'z') {
        all_caps = false;
        break;
     }
  }
  if (all_caps) {
    message->score += 5;
  }

  // Determine if message is spam
  if (message->score >= 15) {
    message->is_spam = true;
  }
}

int main() {
  spam_detection_system message;
  printf("Enter message: ");
  fgets(message.message, 100, stdin);
  message.score = 0;
  message.is_spam = false;

  check_spam(&message);

  if (message.is_spam) {
    printf("This message is spam!\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}
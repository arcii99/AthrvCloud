//FormAI DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGE_LENGTH 100
#define SPAM_THRESHOLD 0.7


int main() {
  char message[MAX_MESSAGE_LENGTH];
  printf("Enter your message: ");
  fgets(message, sizeof(message), stdin);

  // Convert message to lowercase
  for (int i = 0; message[i]; i++) {
    message[i] = tolower(message[i]);
  }

  // Create list of spam keywords
  char* spam_keywords[] = {"free", "guaranteed", "limited time offer", "order now", "offer expires", "click here", "unsubscribe"};
  int keyword_count = sizeof(spam_keywords) / sizeof(spam_keywords[0]);

  // Check if message contains spam keywords
  int spam_count = 0;
  for (int i = 0; i < keyword_count; i++) {
    if (strstr(message, spam_keywords[i])) {
      spam_count++;
    }
  }

  // Determine if message is spam and print result
  double spam_score = (double) spam_count / keyword_count;
  bool is_spam = spam_score > SPAM_THRESHOLD;

  if (is_spam) {
    printf("ALERT: Spam message detected with a spam score of %.2f.", spam_score);
  } else {
    printf("Message is not spam.");
  }

  return 0;
}
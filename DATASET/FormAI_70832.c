//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_SCORE 100

int main(void) {
  char message[1000];
  int spam_score = 0;
  char* spam_keywords[] = {"money", "make", "free", "offer"};

  printf("Please enter your message: ");
  fgets(message, 1000, stdin);

  // remove newline character from message
  message[strcspn(message, "\n")] = '\0';

  for(int i = 0; i < strlen(message); i++) {
    if(message[i] == ' ') {
      continue;
    }
    for(int j = 0; j < sizeof(spam_keywords) / sizeof(spam_keywords[0]); j++) {
      if(strstr(&message[i], spam_keywords[j]) == &message[i]) {
        spam_score += strlen(spam_keywords[j]);
      }
    }
  }

  if(spam_score > MAX_SPAM_SCORE) {
    printf("Warning: Possible spam detected.\n");
    // TODO: add code to handle spam
  } else {
    printf("Message is not spam.\n");
    // TODO: add code to handle non-spam message
  }

  return EXIT_SUCCESS;
}
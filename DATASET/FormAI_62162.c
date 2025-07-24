//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

int main() {
  char message[MAX_MESSAGE_LENGTH];
  int spam_count = 0;
  char* spam_keywords[] = {
    "buy now",
    "click here",
    "limited time",
    "you have won",
    "money back guarantee",
    "amazing deal"
  };
  
  printf("Please enter your message:\n");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  for (int i = 0; i < sizeof(spam_keywords) / sizeof(char*); i++) {
    if (strstr(message, spam_keywords[i]) != NULL) {
      spam_count++;
    }
  }

  if (spam_count > 0) {
    printf("Warning: This message may be spam!\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}
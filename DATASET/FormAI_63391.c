//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

void spam_detector(char string[]) {
  int count_spam = 0;
  char spam_words[5][10] = {"buy", "sale", "discount", "credit", "offer"};

  // the main detection algorithm
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == ' ' || i == 0) {
      for (int j = 0; j < 5; j++) {
        if (strncmp(&string[i], spam_words[j], strlen(spam_words[j])) == 0) {
          count_spam++;
          printf("SPAM DETECTED: %s\n", spam_words[j]);
        }
      }
    }
  }

  // final verdict
  if (count_spam == 0) {
    printf("This message is safe to read.\n");
  } else if (count_spam <= 2) {
    printf("This message may contain spam. Please verify content.\n");
  } else {
    printf("This message almost definitely contains spam.\n");
  }
}

int main() {
  char msg[255];
  
  printf("Please enter your message: ");
  fgets(msg, 255, stdin);
  
  spam_detector(msg);

  return 0;
}
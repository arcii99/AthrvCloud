//FormAI DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
  char spam[100] = "free money! click here for more info!!!";
  char non_spam[100] = "hello, how are you doing today?";

  // analyze spam message
  int num_uppercase = 0;
  int num_exclamation_marks = 0;
  int num_keywords = 0;
  char* spam_keywords[5] = {"click", "money", "free", "limited time offer", "act now"};
  char* token = strtok(spam, " ");
  while(token != NULL) {
    for(int i = 0; i < strlen(token); i++) {
      if(token[i] >= 'A' && token[i] <= 'Z') {
        num_uppercase++;
      }
      if(token[i] == '!') {
        num_exclamation_marks++;
      }
    }
    for(int i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) {
      if(strcmp(token, spam_keywords[i]) == 0) {
        num_keywords++;
      }
    }
    token = strtok(NULL, " ");
  }

  // analyze non-spam message
  int num_uppercase_non_spam = 0;
  int num_exclamation_marks_non_spam = 0;
  int num_keywords_non_spam = 0;
  char* non_spam_keywords[5] = {"hello", "doing", "today", "how", "you"};
  token = strtok(non_spam, " ");
  while(token != NULL) {
    for(int i = 0; i < strlen(token); i++) {
      if(token[i] >= 'A' && token[i] <= 'Z') {
        num_uppercase_non_spam++;
      }
      if(token[i] == '!') {
        num_exclamation_marks_non_spam++;
      }
    }
    for(int i = 0; i < sizeof(non_spam_keywords) / sizeof(non_spam_keywords[0]); i++) {
      if(strcmp(token, non_spam_keywords[i]) == 0) {
        num_keywords_non_spam++;
      }
    }
    token = strtok(NULL, " ");
  }

  // output results
  if(num_uppercase > 10 || num_exclamation_marks > 5 || num_keywords > 3) {
    printf("This message is likely spam.\n");
  } else {
    printf("This message is likely not spam.\n");
  }

  if(num_uppercase_non_spam > 5 || num_exclamation_marks_non_spam > 2 || num_keywords_non_spam > 2) {
    printf("This message is likely not a spam.\n");
  } else {
    printf("This message is likely a spam.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include<stdio.h>
#include<string.h>

#define MAX_MESSAGE_LENGTH 1000
#define SPAM_KEYWORDS_COUNT 5

const char *spam_keywords[SPAM_KEYWORDS_COUNT] = {"lottery", "giveaway", "free money", "click here", "you won"};

int check_message_for_spam(char *message) {
  int i;
  char *token;
  char message_copy[MAX_MESSAGE_LENGTH];
  strcpy(message_copy, message);
  
  /* Convert message to lowercase to enhance matching accuracy */
  for(i = 0; message_copy[i]; i++){
      message_copy[i] = tolower(message_copy[i]);
  }

  /* Check if any of the spam keywords appear in the message */
  token = strtok(message_copy, " ,.!-?");
  while (token != NULL) {
    for (i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
      if (strstr(token, spam_keywords[i]) != NULL) {
        return 1;
      }
    }
    token = strtok(NULL, " ,.!-?");
  }
  return 0;
}

int main() {
  char message[MAX_MESSAGE_LENGTH];
  int is_spam;

  printf("Enter your message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  
  /* Remove the newline character from the message after fgets */
  message[strcspn(message, "\n")] = 0;
  
  is_spam = check_message_for_spam(message);
  
  if (is_spam) {
    printf("This is a spam message\n");
  } else {
    printf("This is not a spam message\n");
  }
  
  return 0;
}
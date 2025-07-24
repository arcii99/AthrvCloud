//FormAI DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to the SPAM Detection System!\n");

  char message[100];
  printf("Please enter a message to be checked for SPAM:\n");
  fgets(message, 100, stdin);
  
  int spam_count = 0;
  
  char* spam_words[] = {"buy now", "limited time offer", "click here", "earn money fast"};
  int word_count = sizeof(spam_words)/sizeof(spam_words[0]);
  
  for(int i = 0; i < word_count; i++) {
    if(strstr(message, spam_words[i]) != NULL) {
      spam_count++;
    }
  }
  
  if(spam_count == 0) {
    printf("This message is not SPAM.\n");
  } else {
    printf("This message is definitely SPAM.\n");
  }
  
  printf("Thanks for using the SPAM Detection System!\n");
  
  return 0;
}
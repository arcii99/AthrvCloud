//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for spam words
int isSpam(char message[]) {
  char spamWords[3][10] = {"buy", "free", "sale"};
  char *token;

  token = strtok(message, " ");

  while(token != NULL) {
    for(int i = 0; i < 3; i++) {
      if(strcmp(token, spamWords[i]) == 0) {
        return 1;
      }
    }
    token = strtok(NULL, " ");
  }

  return 0;
}

int main() {
  char message[100];

  printf("Please enter your message: ");
  fgets(message, 100, stdin);

  if(isSpam(message)) {
    printf("Your message contains spam words. Please retry.\n");
  } else {
    printf("Your message is spam-free. Thank you for submitting it!\n");
  }

  return 0;
}
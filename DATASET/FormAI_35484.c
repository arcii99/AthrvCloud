//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  char keywords[10][20] = {"buy", "sale", "discount", "free", "limited time", "money back", "win", "cash", "offer", "urgent"};
  int count = 0, i, j;

  printf("Enter your message:\n");
  fgets(message, 1000, stdin);  // get input from user

  for (i = 0; i < 10; i++) {
    if (strstr(message, keywords[i]) != NULL) {  // check if keyword exists in message
      count++;
    }
  }

  if (count >= 2) {  // if message contains at least 2 spam keywords
    printf("Spam detected! This message contains %d spam keywords.\n", count);
  } else {
    printf("This message seems to be ok.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];

  // Prompt the user to enter their message
  printf("Enter your message: ");
  fgets(message, 1000, stdin);

  // Get the length of the message
  int length = strlen(message) - 1;

  // Check for spam keywords
  char keywords[5][20] = {"buy", "sale", "free", "click", "winner"};
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (strstr(message, keywords[i]) != NULL) {
      count++;
    }
  }

  // Determine if the message is spam or not
  if (count >= 3 && length > 40) {
    printf("This message is spam!\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}
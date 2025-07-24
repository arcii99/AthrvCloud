//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include<stdio.h>
#include<string.h>

// Configurable variables
#define SPAM_THRESHOLD 3
#define BLACKLIST_SIZE 10

// Function to detect spam
int detect_spam(char message[], char blacklist[][20], int blacklist_size) {
  int count = 0;
  for(int i=0; i<blacklist_size; i++) {
    if(strstr(message, blacklist[i]) != NULL) {
      count++;
      if(count >= SPAM_THRESHOLD) {
        return 1; // Message is spam
      }
    }
  }
  return 0; // Message is not spam
}

// Main function
int main() {

  char blacklist[BLACKLIST_SIZE][20] = {"buy", "sale", "offer", "sex", "viagra", "money", "lottery", "win", "cash", "discount"}; // Predefined blacklist
  char message[1000];
  printf("Enter the message: ");
  fgets(message, 1000, stdin); // Read message from user
  message[strlen(message)-1] = '\0'; // Remove newline character from message

  if(detect_spam(message, blacklist, BLACKLIST_SIZE)) {
    printf("This message is spam!\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a message
#define MAX_LEN 100

// Define the spam threshold
#define SPAM_THRESHOLD 0.5

// Define the maximum number of spam messages allowed
#define MAX_SPAM_MESSAGES 3

// Define the spam message database and the current number of spam messages
char spam_messages[MAX_SPAM_MESSAGES][MAX_LEN];
int num_spam_messages = 0;

// Function to check if a message contains a spam word
int contains_spam(char *message) {
  // Define the spam word database
  char *spam_words[] = {"buy", "now", "discount", "limited", "offer", "sale"};

  // Loop through each spam word
  for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
    // Check if the message contains the current spam word
    if (strstr(message, spam_words[i]) != NULL) {
      return 1; // Return 1 if the message contains a spam word
    }
  }

  return 0; // Return 0 if the message does not contain a spam word
}

int main() {
  // Define the user input buffer
  char input[MAX_LEN];

  // Loop until the user enters "exit"
  while (1) {
    // Get the user input
    printf("Enter your message: ");
    fgets(input, MAX_LEN, stdin);

    // Remove the newline character from the user input
    input[strcspn(input, "\n")] = 0;

    // Check if the message contains a spam word
    if (contains_spam(input)) {
      printf("Warning: Your message contains spam!\n");

      // Add the spam message to the spam message database
      if (num_spam_messages < MAX_SPAM_MESSAGES) {
        strcpy(spam_messages[num_spam_messages], input);
        num_spam_messages++;
      } else {
        printf("Error: Maximum number of spam messages reached!\n");
      }
    } else {
      printf("Your message is safe!\n");
    }

    // Check if the number of spam messages has exceeded the spam threshold
    if ((double)num_spam_messages / MAX_SPAM_MESSAGES > SPAM_THRESHOLD) {
      printf("Warning: You have exceeded the spam limit!\n");
      printf("The following messages were marked as spam:\n");
      for (int i = 0; i < num_spam_messages; i++) {
        printf("- %s\n", spam_messages[i]);
      }
      printf("Please refrain from sending any more spam messages.\n");
      break;
    }
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of spam message

int is_spam(char message[MAX_SIZE]);

int main() {
  char message[MAX_SIZE];
  
  printf("Please enter your message: ");
  fgets(message, MAX_SIZE, stdin);

  if (is_spam(message)) {
    printf("This is a spam message.\n");
  } else {
    printf("This is not a spam message.\n");
  }

  return 0;
}

int is_spam(char message[MAX_SIZE]) {
  char* keywords[] = {"free", "win", "prize", "money", "sex"}; // List of spam keywords
  int len = sizeof(keywords) / sizeof(keywords[0]); // Get length of keyword list
  
  char* token; // Token for keyword search
  int i; // Counter for for-loop
  
  // Convert message to lowercase for easier keyword matching
  for (i = 0; message[i]; i++) {
    message[i] = tolower(message[i]);
  }
  
  // Check for spam keywords in message
  for (i = 0; i < len; i++) {
    token = strstr(message, keywords[i]);
    if (token != NULL) {
      return 1;
    }
  }
  
  // If no spam keywords detected, return 0
  return 0;
}
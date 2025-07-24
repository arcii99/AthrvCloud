//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
  char message[100] = "Hello, world!";
  printf("Original message: %s\n", message);

  // Convert all characters to uppercase
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] -= 32;
    }
  }
  printf("All uppercase message: %s\n", message);

  // Replace all instances of "world" with "Chatbot"
  char *result = strstr(message, "world");
  if (result != NULL) {
    strncpy(result, "Chatbot", 7);
  }
  printf("Replaced message: %s\n", message);

  // Count number of vowels
  int vowels = 0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == 'A' || message[i] == 'E' || message[i] == 'I' ||
        message[i] == 'O' || message[i] == 'U') {
      vowels++;
    }
  }
  printf("Number of vowels: %d\n", vowels);

  // Reverse the message
  char reversed[100];
  int j = 0;
  for (int i = strlen(message) - 1; i >= 0; i--) {
    reversed[j++] = message[i];
  }
  reversed[j] = '\0';
  printf("Reversed message: %s\n", reversed);

  // Check if message is a palindrome
  int isPalindrome = 1;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] != reversed[i]) {
      isPalindrome = 0;
      break;
    }
  }
  if (isPalindrome) {
    printf("The message is a palindrome!\n");
  } else {
    printf("The message is not a palindrome.\n");
  }

  return 0;
}
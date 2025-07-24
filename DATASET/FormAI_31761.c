//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>

int main() {
  char user_input[256];
  char sanitized_input[256];
  int i = 0;

  printf("Enter your input:\n");
  scanf("%s", user_input);

  // Sanitize input by removing non-alpha numeric characters
  while (user_input[i]) {
    if (isalnum(user_input[i])) {
      sanitized_input[i] = user_input[i];
    }
    i++;
  }
  sanitized_input[i] = '\0'; // Terminate string

  printf("Your sanitized input is: %s\n", sanitized_input);

  return 0;
}
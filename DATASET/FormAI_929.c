//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
  char log_message[100];
  int num_warnings = 0;
  int num_errors = 0;

  printf("Enter log messages. Type 'quit' to exit.\n");

  while (1) {
    printf("> ");
    fgets(log_message, 100, stdin); // reads input from user
    log_message[strcspn(log_message, "\n")] = 0; // removes newline character from input

    if (strcmp(log_message, "quit") == 0) {
      break; // exit loop if user types "quit"
    }

    if (strstr(log_message, "warning")) {
      num_warnings++; // increment number of warnings
    }

    if (strstr(log_message, "error")) {
      num_errors++; // increment number of errors
    }
  }

  printf("Log analysis complete.\n");
  printf("%d warnings\n", num_warnings);
  printf("%d errors\n", num_errors);

  return 0;
}
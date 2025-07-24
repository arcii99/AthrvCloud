//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LENGTH 100

// Global variables
char input[MAX_LENGTH];
char output[MAX_LENGTH];
bool is_done = false;

// Function prototypes
void sanitize_input(char* input, char* output);
void print_output();

int main() {
  printf("This program will sanitize your input before displaying it.\n");
  printf("Enter your input (max length %d characters):\n", MAX_LENGTH);
  
  // Read user input asynchronously
  // This is done by using a separate thread that sleeps until input is received
  // Then the input is read and sanitized before being processed by the main thread
  // This allows the user to continue with other tasks while waiting for input
  // The loop breaks when is_done is set to true by the sanitize_input function
  pid_t pid = fork();
  if (pid == 0) {
    scanf("%[^\n]", input);
    sanitize_input(input, output);
    is_done = true;
  }

  while (!is_done) {
    printf("Waiting for input...\n");
    sleep(1);
  }

  print_output();

  return 0;
}

// Sanitize function removes any invalid characters from the user input
void sanitize_input(char* input, char* output) {
  int len = strlen(input);
  int j = 0;

  for(int i = 0; i < len; i++) {
    if (isalnum(input[i])) {
      output[j] = input[i];
      j++;
    }
  }

  // Add '\0' to the end of the output string
  output[j] = '\0';
}

// Print output function displays the sanitized user input
void print_output() {
  printf("The sanitized input is: %s\n", output);
}
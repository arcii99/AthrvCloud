//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

char* sanitize_input(char* input);

int main() {
   char input[MAX_INPUT_SIZE];

   printf("Please enter a string:\n");
   fgets(input, MAX_INPUT_SIZE, stdin);

   char* sanitized_input = sanitize_input(input);

   printf("The sanitized input is: %s", sanitized_input);

   return 0;
}

char* sanitize_input(char* input) {
   char* sanitized_input = malloc(sizeof(char) * MAX_INPUT_SIZE);
   int sanitized_index = 0;

   for (int i = 0; i < strlen(input); i++) {
      if (isalnum(input[i])) {
        sanitized_input[sanitized_index++] = input[i];
      }
   }

   sanitized_input[sanitized_index] = '\0';

   return sanitized_input;
}
//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <ctype.h>

void sanitize_input(char input[], int length) {
   int i;
   for (i = 0; i < length; i++) {
      if (input[i] == '\n') {
         input[i] = '\0'; // replace newline with null terminator
         break;
      }
      else if (input[i] == '\t') {
         input[i] = ' '; // replace tab with space
      }
      else if (isalnum(input[i]) == 0) {
         input[i] = '\0'; // remove non-alphanumeric characters
      }
   }
}

int main() {
   char input[100];
   printf("Enter some input: ");
   fgets(input, sizeof(input), stdin); // get input from user
   sanitize_input(input, sizeof(input)); // sanitize the input
   printf("Sanitized input: %s\n", input);
   return 0;
}
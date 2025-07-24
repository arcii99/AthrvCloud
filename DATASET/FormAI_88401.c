//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   printf("Enter your input: ");
   fgets(input, 100, stdin); // get input from user
   
   // Sanitize the input
   int i, j = 0;
   char sanitized_input[100];
   for (i = 0; i < strlen(input); i++) {
      if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9') || input[i] == '-' || input[i] == '_' || input[i] == '@' || input[i] == '.') {
         sanitized_input[j] = input[i];
         j++;
      } else {
         continue;
      }
   }
   sanitized_input[j] = '\0'; // add null-terminator
   
   // Print sanitized input
   printf("Sanitized input: %s", sanitized_input);
   
   return 0;
}
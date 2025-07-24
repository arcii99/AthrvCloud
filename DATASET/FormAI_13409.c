//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char *input) {
   int i, j = 0;
   char temp;
   for(i=0; input[i]!='\0'; i++) {
      temp = input[i];
      if(isalnum(temp)) {
         input[j++] = tolower(temp);
      }
   }

   input[j] = '\0';
}

int main() {
   char userInput[100];
   printf("Enter the user input: ");
   fgets(userInput, sizeof(userInput), stdin);

   sanitizeInput(userInput);

   printf("The sanitized input is: %s\n", userInput);

   return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
   char input[1000];

   // Read input from the user
   printf("Enter a string: ");
   fgets(input, 1000, stdin);

   // Remove trailing newline
   if (input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
   }

   // Replace any occurrences of 'a' with 'z' in the input string
   for(int i=0; i < strlen(input); i++) {
      if (input[i] == 'a') {
         input[i] = 'z';
      }
   }

   // Capitalize every other word in the input string
   int wordCount = 0;
   char *word = strtok(input, " ");
   while (word != NULL) {
      wordCount++;
      if (wordCount % 2 == 0) {
         word[0] = toupper(word[0]);
      }
      printf("%s ", word);
      word = strtok(NULL, " ");
   }

   return 0;
}
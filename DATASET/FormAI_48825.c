//FormAI DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
   char original_string[MAX_STRING_LENGTH];
   char new_string[MAX_STRING_LENGTH];
   int string_length;

   // prompt the user to enter a string
   printf("Enter a string: ");
   fgets(original_string, MAX_STRING_LENGTH, stdin);

   // remove the trailing newline character if there is one
   string_length = strlen(original_string);
   if (original_string[string_length - 1] == '\n') {
       original_string[string_length - 1] = '\0';
   }

   // create a new string that is a copy of the original string but with all vowels removed
   int i, j;
   j = 0;
   for (i = 0; original_string[i] != '\0'; i++) {
      char current_char = original_string[i];
      if (current_char != 'a' && current_char != 'e' && current_char != 'i' && current_char != 'o' && current_char != 'u'
          && current_char != 'A' && current_char != 'E' && current_char != 'I' && current_char != 'O' && current_char != 'U') {
         new_string[j] = current_char;
         j++;
      }
   }
   new_string[j] = '\0';

   // print the original string and the new string
   printf("\nOriginal string: %s\n", original_string);
   printf("New string: %s\n", new_string);

   return 0;
}
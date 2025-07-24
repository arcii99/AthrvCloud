//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void upperCase(char input[]) {
   int i = 0;
   while(input[i]) {
      if(input[i] >= 'a' && input[i] <= 'z') {
         input[i] = input[i] - 32; // converting to uppercase
      }
      i++;
   }
}

int main() {
   char input[100];
   printf("Enter a string: ");
   scanf("%[^\n]%*c", input); // input with spaces
   
   printf("\nOriginal string: %s", input);
   
   upperCase(input);
   printf("\nUppercase string: %s", input);

   // Counting number of words
   int i, count = 1;
   for (i = 0; input[i] != '\0'; i++) {
      if(input[i] == ' ')
         count++;
   }
   printf("\nNumber of words: %d", count);

   // Reversing the string
   char reverse[100];
   int len = strlen(input);
   for (i = 0; i < len; i++) {
      reverse[i] = input[len-i-1];
   }
   reverse[i] = '\0'; // Null terminator
   printf("\nReversed string: %s", reverse);

   // Finding substring
   char sub[100];
   printf("\nEnter a substring: ");
   scanf("%[^\n]%*c", sub); // input with spaces
   char *result = strstr(input, sub);
   if(result == NULL) {
      printf("\nSubstring not found!");
   }
   else {
      printf("\nSubstring found at position: %d", result-input);
   }

   return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
   char text[1000];
   char word[100];
   int count = 0;
   
   printf("Enter the text:\n");
   fgets(text, 1000, stdin);
   printf("Enter the word to search:\n");
   scanf("%s", word);

   char* token = strtok(text, " ,.-");

   while (token != NULL) {
      if (strstr(token, word) != NULL) {
         count++;
      }
      token = strtok(NULL, " ,.-");
   }

   printf("The word '%s' appears %d times in the text.", word, count);
   
   return 0;
}
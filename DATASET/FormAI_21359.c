//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char text[100];
   char grateful_text[100];
   int i, j;

   printf("Please enter some text that you would like to process: ");
   fgets(text, 100, stdin);

   // Convert text to lowercase
   for (i = 0; text[i]; i++) {
      text[i] = tolower(text[i]);
   }

   // Find grateful words and replace with "thankful"
   char* grateful_words[] = {"grateful", "thanks", "appreciate", "blessed", "thankful"};
   char* replace_word = "thankful";

   j = 0;
   for (i = 0; i < strlen(text); i++) {
      if (isspace(text[i]) || ispunct(text[i])) {
         grateful_text[j++] = text[i];
      } else {
         char temp_word[20];
         int k = 0;
         while (!isspace(text[i]) && !ispunct(text[i])) {
            temp_word[k++] = text[i++];
         }
         temp_word[k] = '\0';

         int is_grateful = 0;
         for (int l = 0; l < 5; l++) {
            if (strcmp(temp_word, grateful_words[l]) == 0) {
               is_grateful = 1;
               break;
            }
         }

         if (is_grateful) {
            strcat(grateful_text, replace_word);
            j += strlen(replace_word);
         } else {
            strcat(grateful_text, temp_word);
            j += strlen(temp_word);
         }
         --i;
      }
   }

   printf("Here is your processed text:\n%s\n", grateful_text);
   return 0;
}
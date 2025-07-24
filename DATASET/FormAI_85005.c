//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORD_LENGTH 25
#define MAX_NUM_WORDS 1000

int main() {

   printf("Welcome to the C Word Frequency Counter!");

   char text[1000];
   char *wordList[MAX_NUM_WORDS];
   int wordCount[MAX_NUM_WORDS];
   int numWords = 0;

   // Read in text from user
   printf("\nEnter some text: ");
   fgets(text, sizeof(text), stdin);

   // Get rid of trailing newline character
   text[strcspn(text, "\n")] = 0;

   // Tokenize text into separate words
   char *token = strtok(text, " ,.!?");

   while(token != NULL) {
      // Convert to lowercase
      for(int i = 0; i < strlen(token); i++)
         token[i] = tolower(token[i]);

      // Check if word already exists in list
      int found = 0;
      for(int i = 0; i < numWords; i++) {
         if(strcmp(wordList[i], token) == 0) {
            wordCount[i]++;
            found = 1;
            break;
         }
      }

      // If word not found, add it to list
      if(!found) {
         wordList[numWords] = (char*) malloc(sizeof(char)*MAX_WORD_LENGTH);
         strncpy(wordList[numWords], token, MAX_WORD_LENGTH);
         wordList[numWords][MAX_WORD_LENGTH-1] = '\0';
         wordCount[numWords] = 1;
         numWords++;
      }

      // Get next word
      token = strtok(NULL, " ,.!?");
   }

   // Print out word frequency table
   printf("\n%-25s %s\n", "Word", "Frequency");
   printf("-------------------------------------------\n");
   for(int i = 0; i < numWords; i++) {
      printf("%-25s %d\n", wordList[i], wordCount[i]);
      free(wordList[i]);
   }

   return 0;
}
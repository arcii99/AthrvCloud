//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100 // Maximum length of a word
#define MAX_LINE_LEN 1000 // Maximum length of a line

int isWordChar(char c) {
   return isalpha(c) || c == '\''; // Return 1 if character is a letter or apostrophe, else return 0.
}

void correctSpelling(char word[]) {
   printf("Did you mean %s? (Y/N): ", word); // Suggest correction to user
   char response = getchar();
   if (toupper(response) == 'Y') {
      printf("Word has been corrected to %s.\n", word);
   } else {
      printf("Word has not been corrected.\n");
   }
   while (getchar() != '\n'); // Flush input buffer
}

int main() {
   char line[MAX_LINE_LEN];

   // Open dictionary file for reading
   FILE *dictionary = fopen("dictionary.txt", "r");
   if (dictionary == NULL) {
      printf("Error: dictionary file could not be opened.\n");
      return 1;
   }

   // Read dictionary into memory
   char **words = (char **)malloc(sizeof(char *) * MAX_LINE_LEN / 2); // Allocate memory for words read from file
   int wordCount = 0;

   while (fgets(line, MAX_LINE_LEN, dictionary)) { // Read dictionary line by line
      char *word = strtok(line, " \n"); // Tokenize line by whitespace and newline characters
      while (word != NULL) {
         words[wordCount] = (char *)malloc(sizeof(char) * MAX_WORD_LEN); // Allocate memory for word
         strcpy(words[wordCount], word); // Copy word into memory
         wordCount++;
         word = strtok(NULL, " \n"); // Get next word in line
      }
   }

   fclose(dictionary); // Close dictionary file

   // Open text file for reading
   FILE *text = fopen("text.txt", "r");
   if (text == NULL) {
      printf("Error: text file could not be opened.\n");
      return 1;
   }

   // Spell-check each word in text file
   while (fgets(line, MAX_LINE_LEN, text)) { // Read text file line by line
      char *word = strtok(line, " \n"); // Tokenize line by whitespace and newline characters
      while (word != NULL) {
         if (strlen(word) > MAX_WORD_LEN) { // Check if word is too long
            printf("%s is too long and will be ignored.\n", word);
            word = strtok(NULL, " \n"); // Get next word in line
            continue;
         }
         int isWord = 1; // Assume word is valid
         for (int i = 0, n = strlen(word); i < n; i++) {
            if (!isWordChar(word[i])) { // Check if character is not valid for a word
               isWord = 0; // Set isWord to false
               break;
            }
            word[i] = tolower(word[i]); // Convert letter to lowercase
         }
         if (!isWord) { // Skip non-word characters
            word = strtok(NULL, " \n"); // Get next word in line
            continue;
         }
         int isCorrect = 0; // Assume word is spelled incorrectly
         for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) { // Check if word is in dictionary
               isCorrect = 1; // Set isCorrect to true
               break;
            }
         }
         if (!isCorrect) { // Suggest correction to user for misspelled word
            correctSpelling(word);
         }
         word = strtok(NULL, " \n"); // Get next word in line
      }
   }

   fclose(text); // Close text file

   // Free dynamically allocated memory
   for (int i = 0; i < wordCount; i++) {
      free(words[i]);
   }
   free(words);

   return 0;
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to check if a character is a letter or not
int isLetter(char c) {
   if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      return 1;
   } else {
      return 0;
   }
}

// Function to perform spell checking on a given word
int spellChecker(char *word, char **dictionary, int dictionarySize) {
   int i, j, misspelled = 1;

   // Remove any non-letter characters at start and end of the word
   while(!isLetter(word[0])) {
      word = &word[1];
   }
   while(!isLetter(word[strlen(word) - 1])) {
      word[strlen(word) - 1] = '\0';
   }

   // Convert the word to lowercase
   for(i = 0; i < strlen(word); i++) {
      if(word[i] >= 'A' && word[i] <= 'Z') {
         word[i] += 'a' - 'A';
      }
   }

   // Check if the word is present in the dictionary
   for(i = 0; i < dictionarySize; i++) {
      if(strcmp(word, dictionary[i]) == 0) {
         misspelled = 0;
         break;
      }
   }

   return misspelled;
}

int main() {
   char *dictionary[] = {"apple", "orange", "banana", "grape", "pear", "mango"};
   int dictionarySize = 6;

   char sentence[100];
   printf("Enter a sentence: ");
   fgets(sentence, 100, stdin);

   char *word = strtok(sentence, " "); // Get first word
   while(word != NULL) {
      if(spellChecker(word, dictionary, dictionarySize)) {
         printf("'%s' is misspelled\n", word);
      } else {
         printf("'%s' is spelled correctly\n", word);
      }
      word = strtok(NULL, " "); // Get next word
   }

   return 0;
}
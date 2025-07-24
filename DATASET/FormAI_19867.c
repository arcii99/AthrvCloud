//FormAI DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char sentence[1000] = "This is a example sentance wiht some speling mistakes."; // sample sentence with some spelling errors
   char *word; // pointer to the words in the sentence
   int lineNum = 1; // line number tracker
   int wordNum = 0; // word number tracker
   int numErrors = 0; // number of spelling errors tracker
   char *dictionary[] = {"example", "sentence", "with", "spelling", "mistakes"}; // dictionary of correct words
   int dictSize = sizeof(dictionary)/sizeof(dictionary[0]); // size of dictionary
   
   printf("Original sentence: %s\n", sentence); // print original sentence
   
   word = strtok(sentence, " ,."); // tokenize the sentence
   
   while (word != NULL) { // loop through each word in the sentence
      wordNum++; // update word number tracker
      
      for (int i = 0; i < strlen(word); i++) { // loop through each character in the word
         word[i] = tolower(word[i]); // convert the character to lowercase
      }
      
      int found = 0; // flag to check if the word is found in the dictionary
      
      for (int i = 0; i < dictSize; i++) { // loop through the dictionary
         if (strcmp(word, dictionary[i]) == 0) { // if the word is found in the dictionary
            found = 1; // set flag to true
            break; // exit the loop
         }
      }
      
      if (!found) { // if the word is not found in the dictionary
         printf("Spelling error found on line %d, word %d: %s\n", lineNum, wordNum, word); // print error message
         numErrors++; // update error tracker
      }
      
      word = strtok(NULL, " ,."); // move to the next word
   }
   
   printf("Number of spelling errors found: %d\n", numErrors); // output number of errors
   
   return 0;
}
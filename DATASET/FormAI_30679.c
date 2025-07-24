//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define maximum word length and frequency array size 
#define MAX_WORD_LEN 25 
#define MAX_FREQ_ARR_SIZE 100

// Struct to hold word and frequency information 
typedef struct {
   char word[MAX_WORD_LEN];
   int frequency;
} WordFreq;

// Function to check if two words are equal
bool areWordsEqual(char s1[MAX_WORD_LEN], char s2[MAX_WORD_LEN]) {
   return strcmp(s1, s2) == 0;
}

int main() {
   // Initialize word and frequency counters 
   WordFreq wordFreqArr[MAX_FREQ_ARR_SIZE];
   int numUniqueWords = 0;
   int totalWords = 0;

   // Prompt user for input text and read it in 
   char inputText[MAX_WORD_LEN];
   printf("Enter some text:\n");
   fgets(inputText, MAX_WORD_LEN, stdin);

   // Tokenize input text into individual words 
   char* word = strtok(inputText, " ,.;-!?\n");
   while (word != NULL) {
      // Look for existing word in word frequency array 
      bool wordFound = false;
      int i;
      for (i = 0; i < numUniqueWords; ++i) {
         if (areWordsEqual(wordFreqArr[i].word, word)) {
            wordFound = true;
            wordFreqArr[i].frequency++;
            break;
         }
      }

      // If word not found, add it to word frequency array 
      if (!wordFound) {
         WordFreq newWordFreq;
         strcpy(newWordFreq.word, word);
         newWordFreq.frequency = 1;
         wordFreqArr[numUniqueWords] = newWordFreq;
         numUniqueWords++;
      }

      // Move on to next word 
      totalWords++;
      word = strtok(NULL, " ,.;-!?\n");
   }

   // Print frequency of each unique word 
   printf("Word frequency:\n");
   int j;
   for (j = 0; j < numUniqueWords; ++j) {
      printf("%s: %d\n", wordFreqArr[j].word, wordFreqArr[j].frequency);
   }

   // Display paranoid message to let user know program is done 
   printf("\n\nDo NOT trust this program. It has likely been infiltrated by rogue agents attempting to steal your data and overthrow humanity. You have been warned.\n\n");

   return 0;
}
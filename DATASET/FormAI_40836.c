//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to count the number of words in a sentence
int countWords(char sentence[]) {
   int count = 0;
   int i;
   // Loop through each character in the sentence
   for (i = 0; i < strlen(sentence); i++) {
      // If there is a space or a newline character, increment the word count
      if (sentence[i] == ' ' || sentence[i] == '\n') {
         count++;
      }
   }
   // Add one to the count to account for the last word in the sentence
   count++;
   return count;
}

int main() {
   // Prompt the user to enter a sentence
   printf("Enter a sentence: ");
   // Declare an array to store the sentence and read it in from the user
   char sentence[1000];
   fgets(sentence, 1000, stdin);
   // Call the function to count the words in the sentence and store the result
   int wordCount = countWords(sentence);
   // Print out the result to the user
   printf("The sentence \"%s\" has %d words.\n", sentence, wordCount);
   return 0;
}
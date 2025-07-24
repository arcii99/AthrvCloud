//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* This program takes a sentence as input and calculates the frequency 
   of each word in the sentence */

int main() {

  // Print a welcome message
  printf("Welcome to the C Word Frequency Counter!\n");

  char sentence[1000];

  // Get input sentence from user
  printf("\nPlease enter a sentence:\n");
  fgets(sentence, 1000, stdin);

  int length = strlen(sentence);

  // Convert all characters to lowercase for consistency
  for(int i = 0; i < length; i++) {
    sentence[i] = tolower(sentence[i]);
  }

  // Count the frequency of each word in the sentence
  int frequency[1000] = {0};
  char word[100];

  int position = 0;
  int word_count = 0;

  for(int i = 0; i < length; i++) {

    // Check if character is alphabetic or whitespace
    if(isalpha(sentence[i]) || isspace(sentence[i])) {

      // If character is whitespace, we have found a new word
      if(isspace(sentence[i]) || i == length - 1) {

        // Null terminate the current word
        word[position] = '\0';

        // Reset position for next word
        position = 0;

        // Increment word count
        word_count++;

        // Check if word is already in frequency table
        int found = 0;
        for(int j = 0; j < word_count; j++) {
          if(strcmp(word, &sentence[frequency[j]]) == 0) {
            frequency[j]++;
            found = 1;
            break;
          }
        }

        // If word is not already in frequency table, add it
        if(!found) {
          frequency[word_count] = i;
        }
      }

      // If character is alphabetic, add it to current word
      else {
        word[position++] = sentence[i];
      }
    }
  }

  // Print the frequency table
  printf("\nWord Frequency Table:\n");
  for(int i = 0; i < word_count; i++) {
    printf("%s   %d\n", &sentence[frequency[i]], frequency[i]);
  }

  return 0;

}
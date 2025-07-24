//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20 // maximum word length in the alien language
#define NUM_VOWELS 3 // number of vowels in the alien language

// function to translate a single word from the alien language to English
void translateWord(char alienWord[MAX_WORD_LENGTH], char englishWord[MAX_WORD_LENGTH]) {
  // assume that each vowel in the alien language corresponds to a unique English letter
  char vowels[NUM_VOWELS] = {'a', 'e', 'i'};
  
  // loop through each letter in the alien word
  for (int i = 0; i < strlen(alienWord); i++) {
    // find the index of the vowel in the vowels array
    int vowelIndex = -1;
    for (int j = 0; j < NUM_VOWELS; j++) {
      if (alienWord[i] == vowels[j]) {
        vowelIndex = j;
        break;
      }
    }

    // if the letter is a vowel, replace it with the corresponding English letter
    if (vowelIndex != -1) {
      englishWord[i] = 'a' + vowelIndex;
    } else {
      englishWord[i] = alienWord[i];
    }
  }

  // add the null terminator at the end of the English word
  englishWord[strlen(alienWord)] = '\0';
}

int main() {
  char alienWord[MAX_WORD_LENGTH];
  char englishWord[MAX_WORD_LENGTH];

  printf("Enter a word in the alien language: ");
  scanf("%s", alienWord);

  translateWord(alienWord, englishWord);

  printf("The English equivalent of '%s' is '%s'.\n", alienWord, englishWord);

  return 0;
}
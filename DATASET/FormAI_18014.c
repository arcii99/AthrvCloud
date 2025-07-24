//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <string.h>

// Define maximum length of dictionary word
#define MAX_WORD_LEN 20
// Define maximum number of words in dictionary
#define MAX_DICT_WORDS 100

// Dictionary of words to check against
char dict[MAX_DICT_WORDS][MAX_WORD_LEN+1] = {"retro", "style", "program", "unique", "spell", "checking", "example", "code", "snippets", "compile", "run", "errors", "glitch", "debug", "syntax", "semantics"};

// Function to check if a given word is spelled correctly
int spellCheck(char* word){
  // Loop through each word in the dictionary
  for(int i = 0; i < MAX_DICT_WORDS; i++){
    // If the word matches a word in the dictionary, return 1
    if(strcmp(word, dict[i]) == 0){
      return 1;
    }
  }
  // If the word doesn't match any words in the dictionary, return 0
  return 0;
}

int main(){
  char input[100]; // Define input buffer to store user input
  char wordBuffer[MAX_WORD_LEN+1]; // Define buffer to store each detected word
  int bufferIndex = 0; // Index for the current position in wordBuffer

  printf("SPELL CHECK\n");
  printf("Enter some text to check for spelling errors:\n");
  
  // Loop through each character in the user's input
  while(fgets(input, 100, stdin)){
    for(int i = 0; i < strlen(input); i++){
      char currentChar = input[i];
      // If the current character is a letter, add it to the current word buffer
      if(currentChar >= 'a' && currentChar <= 'z'){
        wordBuffer[bufferIndex] = currentChar;
        bufferIndex++;
      }
      // If the current character is not a letter, it marks the end of a word, so process the word
      if(currentChar < 'a' || currentChar > 'z'){
        // Null-terminate the wordBuffer to turn it into a C string
        wordBuffer[bufferIndex] = '\0';
        // Check if the word is spelled correctly
        if(!spellCheck(wordBuffer)){
          printf("ERROR: %s is misspelled\n", wordBuffer);
        }
        // Reset the bufferIndex to start a new word
        bufferIndex = 0;
      }
    }
    // Clear the input buffer before reading the next input
    memset(input, 0, 100);
  }
  return 0;
}
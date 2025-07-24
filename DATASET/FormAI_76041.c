//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char sentence[1000], word[100];
  int count = 0;
  
  printf("Please enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin); //get sentence from user
  
  printf("Please enter a word to count its frequency: ");
  scanf("%s", word); //get word from user
  
  char* token = strtok(sentence, " "); //tokenize sentence
  
  while(token != NULL) { //iterate until no more tokens
    if(strcmp(token, word) == 0) { //compare token with the word
      count++; //increment count if word is found
    }
    token = strtok(NULL, " "); //get next token
  }
  
  printf("The word '%s' appears in the sentence %d times.", word, count);
  
  return 0;
}
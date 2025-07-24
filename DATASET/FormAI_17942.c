//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[256];
  printf("Enter an English sentence to translate to C Cat Language: \n");
  fgets(sentence, sizeof(sentence), stdin); // get string input from user
  
  char* word;
  word = strtok(sentence, " ");  // tokenize input string into words
  
  printf("Translated sentence: ");
  while (word != NULL) {
    printf("%s meow ", word); // append "meow" to each word in the sentence
    word = strtok(NULL, " "); // get next word
  }
  
  printf("\n");
  
  return 0; // exit program
}
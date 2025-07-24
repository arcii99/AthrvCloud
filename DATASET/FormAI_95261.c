//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a phrase in C Cat Language:\n");
  fgets(input, 100, stdin);

  // Translation dictionary
  char* cat_words[10] = {"meow", "purr", "hiss", "scratch", "lick", "nap", "play", "climb", "hunt", "eat"};
  char* english_words[10] = {"hello", "please", "no", "stop", "yes", "sleep", "fun", "up", "kill", "food"};

  // Loop through each "word" in the input
  char* word = strtok(input, " ");
  while(word != NULL) {
    // Translate the word if it's a C Cat word
    int i;
    for(i=0; i<10; i++) {
      if(strcmp(word, cat_words[i]) == 0) {
        printf("%s ", english_words[i]);
        break;
      }
    }
    // If the word is not a C Cat word, print it as is
    if(i == 10) printf("%s ", word);

    // Move on to the next word
    word = strtok(NULL, " ");
  }
  return 0;
}
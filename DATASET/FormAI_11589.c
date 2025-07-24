//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
  // Define the C Cat Dictionary
  char *words[10] = {"meow", "purrs", "hiss", "paw", "whiskers", "tail", "claw", "scratches", "kitten", "catnip"};

  printf("Welcome to the C Cat Language Translator!\n");
  printf("Enter a sentence to be translated to C Cat Language: ");

  // Get the user input sentence
  char sentence[100];
  fgets(sentence, sizeof(sentence), stdin);

  // Replace each English word with its matching C Cat word
  char *word = strtok(sentence, " \n");
  while (word != NULL) {
    for (int i = 0; i < 10; i++) {
      if (strcmp(word, words[i]) == 0) {
        printf("%s ", words[i]);
        break;
      }
    }
    word = strtok(NULL, " \n");
  }

  // End the translated sentence with a meow
  printf("meow\n");

  return 0;
}
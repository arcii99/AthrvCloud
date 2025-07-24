//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a sentence in C Cat Language: ");
  fgets(input,100,stdin);
  
  // Loop through the string to translate each word
  char *word = strtok(input," \n");
  printf("Translation into English: ");
  while (word != NULL) {
    if (strcmp(word, "meow") == 0) {
      printf("Hello");
    } else if (strcmp(word, "purr") == 0) {
      printf("I am happy");
    } else if (strcmp(word, "hiss") == 0) {
      printf("I am angry");
    } else if (strcmp(word, "scratch") == 0) {
      printf("I need attention");
    } else if (strcmp(word, "sleep") == 0) {
      printf("Goodnight");
    } else {
      printf("%s", word);
    }
    printf(" ");
    word = strtok(NULL," \n");
  }
  return 0;
}
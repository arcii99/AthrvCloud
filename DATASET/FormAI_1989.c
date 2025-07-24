//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to translate words from C Alien language to English
void translate(char word[]) {
  if (strcmp(word, "Iovve") == 0) {
    printf("My love, ");
  } else if (strcmp(word, "yraa") == 0) {
    printf("you are ");
  } else if (strcmp(word, "xya") == 0) {
    printf("the ");
  } else if (strcmp(word, "znaa") == 0) {
    printf("sun ");
  } else if (strcmp(word, "zzla") == 0) {
    printf("shines ");
  } else if (strcmp(word, "kree") == 0) {
    printf("bright ");
  } else if (strcmp(word, "qklu") == 0) {
    printf("and ");
  } else if (strcmp(word, "zkla") == 0) {
    printf("beautiful. ");
  } else {
    printf("%s ", word);
  }
}

int main() {
  char message[100];
  printf("Enter a message in C Alien language:\n");
  fgets(message, 100, stdin);

  printf("Translation:\n");
  char *word = strtok(message, " ");
  while (word != NULL) {
    translate(word);
    word = strtok(NULL, " ");
  }

  printf("\nYour message in English sounds so romantic!");

  return 0;
}
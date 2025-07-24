//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert C Cat Language to English
char* translate_to_english(char* sentence) {
  char* translation = (char*) malloc(MAX_LENGTH * sizeof(char));
  int i = 0;
  char delimiter[] = " ";
  char* token = strtok(sentence, delimiter);
  while (token != NULL) {
    if (strcmp(token, "meow") == 0) {
      strcat(translation, "hello");
    } else if (strcmp(token, "purr") == 0) {
      strcat(translation, "thank you");
    } else if (strcmp(token, "hiss") == 0) {
      strcat(translation, "no");
    } else {
      strcat(translation, token);
    }
    strcat(translation, " ");
    token = strtok(NULL, delimiter);
  }
  return translation;
}

// Main function
int main() {
  char sentence[MAX_LENGTH] = "meow, my name is Whiskers";
  printf("Translate from C Cat Language to English -\n");
  printf("Input sentence: %s\n", sentence);
  char* english_sentence = translate_to_english(sentence);
  printf("Translated sentence: %s\n", english_sentence);
  free(english_sentence);
  return 0;
}
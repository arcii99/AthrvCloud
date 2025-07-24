//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

typedef struct {
  char* c_cat_word;
  char* english_word;
} word_translation;

word_translation dictionary[] = {
  {"meow", "hello"},
  {"prrr", "goodbye"},
  {"hiss", "stop"},
  {"mew", "please"},
  {"purrpurr", "thank you"},
  {"paw", "yes"},
  {"tail", "no"},
  {"scratch", "sorry"},
};

int num_translations = 8;

char* translate_word(char* c_cat_word) {
  int i;
  for (i = 0; i < num_translations; i++) {
    if (strcmp(c_cat_word, dictionary[i].c_cat_word) == 0) {
      return dictionary[i].english_word;
    }
  }
  return "";
}

int main() {
  char input[20];
  char* translation;
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Enter a C cat word to translate into English:\n");
  scanf("%s", input);
  translation = translate_word(input);
  if (strlen(translation) == 0) {
    printf("Sorry, that word is not in the dictionary.\n");
  } else {
    printf("The English word for %s is %s.\n", input, translation);
  }
  return 0;
}
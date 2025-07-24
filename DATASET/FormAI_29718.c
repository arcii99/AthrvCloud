//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

struct Word {
  char english[20];
  char c_cat[20];
};

void translate(struct Word dictionary[], char* word) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(dictionary[i].english, word) == 0) {
      printf("%s\n", dictionary[i].c_cat);
      return;
    }
  }
  printf("I do not know how to say %s in C Cat language.\n", word);
}

int main() {
  struct Word dictionary[10];
  strcpy(dictionary[0].english, "hello");
  strcpy(dictionary[0].c_cat, "meow");
  strcpy(dictionary[1].english, "world");
  strcpy(dictionary[1].c_cat, "pur");
  strcpy(dictionary[2].english, "goodbye");
  strcpy(dictionary[2].c_cat, "hiss");
  strcpy(dictionary[3].english, "program");
  strcpy(dictionary[3].c_cat, "codee");
  strcpy(dictionary[4].english, "variable");
  strcpy(dictionary[4].c_cat, "scratchy");
  strcpy(dictionary[5].english, "computer");
  strcpy(dictionary[5].c_cat, "boxxy");
  strcpy(dictionary[6].english, "function");
  strcpy(dictionary[6].c_cat, "meowthod");
  strcpy(dictionary[7].english, "integer");
  strcpy(dictionary[7].c_cat, "purrfect");
  strcpy(dictionary[8].english, "floating");
  strcpy(dictionary[8].c_cat, "floaty");
  strcpy(dictionary[9].english, "string");
  strcpy(dictionary[9].c_cat, "yarn");

  printf("Welcome to the C Cat Language Translator!\n");
  printf("Enter a word in English to translate to C Cat language.\n");

  char word[20];
  while (strcmp(word, "exit") != 0) {
    scanf(" %s", word);
    translate(dictionary, word);
  }

  return 0;
}
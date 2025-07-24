//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
  char c_cat_language[] = "meow meow purrrr hiss purrrr meow";
  char trans_language[100] = "";
  
  printf("Original C Cat Language: %s\n", c_cat_language);
  
  // Translation Mapping
  char meow[] = {'h', 'e', 'l', 'l', 'o'};
  char purrrr[] = {'w', 'e', 'l', 'c', 'o', 'm', 'e'};
  char hiss[] = {'g', 'o', 'o', 'd', 'b', 'y', 'e'};

  char* word = strtok(c_cat_language, " ");
  while (word != NULL) {
    if (strcmp(word, "meow") == 0) {
      strcat(trans_language, meow);
    } else if (strcmp(word, "purrrr") == 0) {
      strcat(trans_language, purrrr);
    } else if (strcmp(word, "hiss") == 0) {
      strcat(trans_language, hiss);
    }
    strcat(trans_language, " ");
    word = strtok(NULL, " ");
  }

  printf("Translated Language: %s\n", trans_language);
  
  return 0;
}
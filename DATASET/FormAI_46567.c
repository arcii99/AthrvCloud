//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

/* C Cat Language Translator */
void translate_cat_language(char* input_str) {
  char buffer[1024] = {0};
  int is_meowing = 0;
  for (int i = 0; i < strlen(input_str); i++) {
    char c = input_str[i];
    if (c == ' ') {
      strcat(buffer, " ");
      continue;
    }
    if (is_meowing) {
      strcat(buffer, "meow ");
      is_meowing = 0;
      continue;
    }
    if (c == 'C' || c == 'c') {
      strcat(buffer, "meow ");
    } else if (c == 'A' || c == 'a') {
      strcat(buffer, "purr ");
    } else if (c == 'T' || c == 't') {
      strcat(buffer, "hiss ");
    } else {
      strcat(buffer, "meow ");
    }
    is_meowing = 1;
  }
  printf("%s\n", buffer);
}

/* Sample Usage */
int main() {
  char input[] = "Cat";
  printf("Input: %s\n", input);
  printf("Translation: ");
  translate_cat_language(input);

  char input2[] = "Catch some mice!";
  printf("Input: %s\n", input2);
  printf("Translation: ");
  translate_cat_language(input2);

  return 0;
}
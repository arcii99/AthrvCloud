//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
  char* english[6] = {"Hello", "Goodbye", "Thank You", "Yes", "No", "How are you?"};
  char* cat[6] = {"Meow", "Purr", "Meow Meow", "Meow Meow Meow", "Hiss", "Meow Meow Meow Meow"};

  printf("Welcome to the C Cat Language Translator program!\n\n");
  printf("Enter an English phrase to translate to Cat language:\n");

  char input[50];
  fgets(input, 50, stdin);
  input[strcspn(input, "\n")] = 0;

  int i;
  for (i = 0; i < 6; i++) {
    if (strcmp(input, english[i]) == 0) {
      printf("The Cat translation is: %s\n", cat[i]);
      break;
    }
  }

  if (i == 6) {
    printf("Sorry, that phrase cannot be translated to Cat language.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the C Alien Language Translator!\n");

  char *inputs[] = {"^", "^^", "^~", "^^^", "^_^", "^o^", "^0^", "^-^", "^_^", "^_^_^", "^_^_^_^"};
  char *outputs[] = {"Hello", "Hi", "Greetings", "Salutations", "Hey there", "Howdy", "What's up", "Yo", "Greetings and salutations", "Hiya"};

  while (1) {
    char input[10];

    printf("Enter an alien code:\n");
    scanf("%s", input);

    int index = -1;

    for (int i = 0; i < 11; i++) {
      if (strcmp(input, inputs[i]) == 0) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      printf("Invalid input. Please try again.\n");
      continue;
    }

    printf("%s!\n", outputs[index]);
  }

  return 0;
}
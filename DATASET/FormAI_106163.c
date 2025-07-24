//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to the Cat Language Translator!\n");
  printf("Please enter your message in Cat Language: ");

  // read input from user
  char input[1000];
  fgets(input, sizeof(input), stdin);

  // translate input to English
  char english[1000] = "";
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == 'm') {
      strcat(english, "meow");
    } else if (input[i] == 'p') {
      strcat(english, "purr");
    } else if (input[i] == 'h') {
      strcat(english, "hiss");
    } else if (input[i] == 'c') {
      strcat(english, "cat");
    } else { // if character doesn't match any of the above, just add it to English string
      char c[2] = "";
      c[0] = input[i];
      strcat(english, c);
    }
  }

  // output translated message
  printf("Your translated message is: %s\n", english);

  return 0;
}